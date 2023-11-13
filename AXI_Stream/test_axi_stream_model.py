import cocotb
import random
from typing import TypeVar, List, Union
from collections import deque
from cocotb.triggers import Timer, FallingEdge, RisingEdge
from cocotb.triggers import ClockCycles

def hex_div(str, stride):
    list_len = int(len(str)/stride)
    list = [""]*list_len
    for i in range(list_len):
        list[i] = str[i*stride: (i+1)*stride]
    return list

class clockDomain(object):
    def __init__(self, clkSig, period, unit, resetSig=None, resetActiveHigh=True):
        self.clk = clkSig
        self.reset = resetSig
        self.period = period
        self.unit = unit
        self.resetActiveHigh = resetActiveHigh

    async def doReset(self):
        clockCycle = ClockCycles(self.clk, 10, True)
        if self.resetActiveHigh:
            self.reset <= 1
        else:
            self.reset <= 0
        await clockCycle
        if self.resetActiveHigh:
            self.reset <= 0
        else:
            self.reset <= 1
    
    async def genClk(self):
        self.clk.value = 0
        while True:
            await Timer(self.period/2, self.unit)
            self.clk.value = 1
            await Timer(self.period/2, self.unit)
            self.clk.value = 0
    
    async def start(self):
        clockTh = cocotb.start_soon(self.genClk())
        resetTh = cocotb.start_soon(self.doReset())
        await resetTh.join()
        return clockTh
    
class inputStream(object):
    def __init__(self, valid_in=0, data_in=0, keep_in="0000", last_in=0, ready_out=1, valid_insert=0, header_insert=0, keep_insert="0000"):
        self.valid_in = valid_in
        self.data_in = data_in
        self.keep_in = keep_in
        self.last_in = last_in
        self.ready_out = ready_out
        self.valid_insert = valid_insert
        self.header_insert = header_insert
        self.keep_insert = keep_insert
        
class headerStream(inputStream):
    def __init__(self, header_insert=0, keep_insert="0001"):
        super().__init__(valid_insert=1, header_insert=header_insert, keep_insert=keep_insert)
        
class dataStream(inputStream):
    def __init__(self, data_in=0):
        super().__init__(valid_in=1, data_in=data_in, keep_in="1111")

class lastStream(inputStream):
    def __init__(self, data_in=0, keep_in="1111"):
        super().__init__(valid_in=1, data_in=data_in, keep_in=keep_in, last_in=1)
    
class inputDriver(object):
    def __init__(self, clk, valid_in, data_in, keep_in, last_in, ready_out, valid_insert, header_insert, keep_insert, ready_in, ready_insert):
        self.clk = clk
        
        # self.dut = dut
        self.valid_in = valid_in
        self.data_in = data_in
        self.keep_in = keep_in
        self.last_in = last_in
        self.ready_out = ready_out
        self.valid_insert = valid_insert
        self.header_insert = header_insert
        self.keep_insert = keep_insert
        
        self.ready_in = ready_in
        self.ready_insert = ready_insert

        self.taskQ = deque()
        self.aimInput = deque()
        self.aimResult = deque()
        
    async def initialAll(self):
        self.valid_in.value = 0
        self.data_in.value = 0
        self.keep_in.value = int("0000", 2)
        self.last_in.value = 0
        self.ready_out.value = 1
        self.valid_insert.value = 0
        self.header_insert.value = 0
        self.keep_insert.value = int("0000", 2)
        await RisingEdge(self.clk)
    
    async def timeGen(self, transaction):
        self.ready_out.value = 1
        edge = RisingEdge(self.clk)
        if isinstance(transaction, dataStream):
            while self.ready_in.value != 1:
                await edge
            self.valid_in.value = transaction.valid_in
            self.data_in.value = transaction.data_in
            self.keep_in.value = int(transaction.keep_in, 2)
            self.last_in.value = transaction.last_in
            
            self.aimInput.append(transaction.data_in)
            
            data_in = hex_div(hex(transaction.data_in)[2:], 2)
            
            if transaction.valid_in and self.ready_in:
                for i in range(len(data_in)):
                    self.aimResult.append(data_in[i])
            await edge
        elif isinstance(transaction, headerStream):
            while self.ready_insert.value != 1:
                await edge
            self.valid_insert.value = transaction.valid_insert
            self.header_insert.value = transaction.header_insert
            self.keep_insert.value = int(transaction.keep_insert, 2)
            
            self.aimInput.append(transaction.header_insert)
            
            data_in = hex_div(hex(transaction.header_insert)[2:], 2)
            keep_in = hex_div(transaction.keep_insert, 1)
            
            if transaction.valid_insert and self.ready_insert:
                for i in range(len(keep_in)):
                    if(keep_in[i] == "1"):
                        self.aimResult.append(data_in[i])
            await edge
        elif isinstance(transaction, lastStream):
            while self.ready_in.value != 1:
                await edge
            self.valid_in.value = transaction.valid_in
            self.data_in.value = transaction.data_in
            self.keep_in.value = int(transaction.keep_in, 2)
            self.last_in.value = transaction.last_in
            self.valid_insert.value = 0
            
            self.aimInput.append(transaction.data_in)
            
            data_in = hex_div(hex(transaction.data_in)[2:], 2)
            keep_in = hex_div(transaction.keep_in, 1)
            
            # print("$$", data_in)
            for i in range(len(keep_in)):
                if(keep_in[i] == "1"):
                    self.aimResult.append(data_in[i])
            await edge
        elif isinstance(transaction, inputStream):
            while self.ready_in.value != 1:
                await edge
            self.valid_in.value = transaction.valid_in
            self.data_in.value = transaction.data_in
            self.keep_in.value = int(transaction.keep_in, 2)
            self.last_in.value = transaction.last_in
            
            self.aimInput.append(transaction.data_in)
            
            data_in = hex_div(hex(transaction.data_in)[2:], 2)
            
            if transaction.valid_in and self.ready_in:
                for i in range(len(data_in)):
                    self.aimResult.append(data_in[i])
            await edge
        else:
            self.valid_in.value = 0
            self.ready_out.value = 1
            self.last_in.value = 0
            await edge
            
        cocotb.log.info("Get a transaction in Input Driver")

    async def taskMonitor(self):
        edge = RisingEdge(self.clk)
        while True:
            if len(self.taskQ) != 0:
                await self.timeGen(self.taskQ.popleft())
            else:
                await edge

    def addTransaction(self, transaction):
        self.taskQ.append(transaction)
        
class outputMonitor(object):
    def __init__(self, clk, valid_out, ready_out, data_out, keep_out, last_out):
        self.clk = clk
        
        self.valid_out = valid_out
        self.ready_out = ready_out
        self.data_out = data_out
        self.keep_out = keep_out
        self.last_out = last_out
        
        self.recvQ = deque()
        self.taskCounter = 0
        
    async def taskMonitor(self):
        edge = RisingEdge(self.clk)
        while True:
            if self.valid_out.value == 1 and self.ready_out.value == 1:
                self.taskCounter += 1
                cocotb.log.info("Get a transaction in Output Monitor")
                
                data_out = hex_div(hex(self.data_out.value)[2:].ljust(8, '0'), 2)
                keep_out = hex_div(bin(self.keep_out.value)[2:], 1)
                
                # print("##", keep_out)
                for i in range(len(keep_out)):
                    if(keep_out[i] == "1"):
                        self.recvQ.append(data_out[i])
            await edge
                        
    def getRecvNum(self):
        return self.taskCounter
    
class axiStreamTb(object):
    def __init__(self, dut):
        self.dut = dut
        self.inDriver = inputDriver(dut.clk, dut.valid_in, dut.data_in, dut.keep_in, dut.last_in, dut.ready_out, dut.valid_insert, dut.header_insert, dut.keep_insert, dut.ready_in, dut.ready_insert)
        self.outputMonitor = outputMonitor(dut.clk, dut.valid_out, dut.ready_out, dut.data_out, dut.keep_out, dut.last_out)
        self.clockCtrl = clockDomain(self.dut.clk, 10, "ns", self.dut.rst_n, False)
        
    async def start(self):
        self.inDriverTh = cocotb.start_soon(self.inDriver.taskMonitor())
        self.outputMonitorTh = cocotb.start_soon(self.outputMonitor.taskMonitor())
        self.clockCtrlTh = await self.clockCtrl.start()
        
    def stop(self):
        self.inDriverTh.kill()
        self.outputMonitorTh.kill()
        self.clockCtrlTh.kill()
        
    def addTransaction(self, transaction):
        self.inDriver.addTransaction(transaction)
        
    async def waitAllDone(self):
        edge = RisingEdge(self.dut.clk)
        while not self.outputMonitor.last_out == 1:
            await edge
        # print("$$ I am here")
        
        await self.initialTb()

    def resultCheck(self):
        while len(self.inDriver.aimResult):
            print(self.inDriver.aimResult.popleft(), end="\t")
        print("\n/**********/")
        
        while len(self.outputMonitor.recvQ):
            print(self.outputMonitor.recvQ.popleft(), end="\t")
        print("\n/**********/")
        # assert self.inDriver.aimResult == self.outputMonitor.recvQ
        
    async def initialTb(self):
        edge = RisingEdge(self.dut.clk)
        await self.inDriver.initialAll()
        

def genRandomData():
    return random.randint(int("11111111", 16), int("ffffffff", 16))

@cocotb.test()
async def run_test(dut):
    tb = axiStreamTb(dut)
    await tb.start()
    headData = headerStream(int("12345678", 16), "0011")
    tb.addTransaction(headData)
    for i in range(5):
        randData = genRandomData()
        tb.addTransaction(dataStream(randData))
    tb.addTransaction(lastStream(genRandomData(), "1100"))
    
    # await Timer(1000, "ns")
    await tb.waitAllDone()
    
    headData = headerStream(int("12345678", 16), "0111")
    tb.addTransaction(headData)
    for i in range(20):
        randData = genRandomData()
        tb.addTransaction(inputStream(data_in=genRandomData(), valid_in=random.randint(0, 1), ready_out=random.randint(0, 1), keep_in="1111"))
    tb.addTransaction(lastStream(genRandomData(), "1100"))
    
    await tb.waitAllDone()
    
    tb.stop()
    tb.resultCheck()