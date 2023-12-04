FROM sherlocat/cocotb:latest

# Copy Project
WORKDIR /home/project/AXI_Stream
COPY ./AXI_Stream/* ./
RUN ls
RUN make