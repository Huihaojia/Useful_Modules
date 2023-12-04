FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y wget
RUN apt-get install -y zlib1g-dev libbz2-dev libssl-dev libncurses5-dev
RUN apt-get install -y libffi-dev
# Build Python
WORKDIR /usr/local/python
RUN wget https://www.python.org/ftp/python/3.12.0/Python-3.12.0.tgz
RUN tar -zxvf Python-3.12.0.tgz
RUN apt-get install -y build-essential
RUN mkdir ./python12
WORKDIR /usr/local/python/Python-3.12.0
RUN ./configure --with-ssl prefix=/usr/local/python/python12
RUN make
RUN make install
WORKDIR /usr/local/python/python12/bin
RUN cp python3.12 python
# Build Cocotb
RUN apt-get install -y python3-pip python3-setuptools python3-dev
# 锁版本
RUN pip3 install cocotb
# Build Verilator
RUN apt-get install -y git help2man perl python3 make autoconf g++ flex bison ccache
RUN apt-get install -y libgoogle-perftools-dev numactl perl-doc
RUN apt-get install -y libfl2
RUN apt-get install -y libfl-dev
WORKDIR /usr/local/verilator
RUN git clone https://github.com/verilator/verilator

# wget 找到release的页面找稳定版本
WORKDIR /usr/local/verilator/verilator
RUN unset VERILATOR_ROOT
RUN autoconf
RUN ./configure
RUN make
RUN make install
# Copy Project
WORKDIR /home/project/AXI_Stream
COPY ../AXI_Stream/* ./
RUN make