FROM ubuntu:22.04

# Install dependencies
RUN apt update && apt install -y \
    build-essential \
    cmake \
    make \
    nasm \
    qemu-system-x86 \
    grub-pc-bin \
    xorriso \
    bison \
    flex \
    libgmp3-dev \
    libmpc-dev \
    libmpfr-dev \
    texinfo \
    curl

# Define environment variables for toolchain
ENV TARGET=x86_64-elf
ENV PREFIX=/usr/local/cross

# Create directory for toolchain
RUN mkdir -p /usr/src/toolchain

# Install Binutils (including x86_64-elf-ld)
RUN cd /usr/src/toolchain && \
    curl -O http://ftp.gnu.org/gnu/binutils/binutils-2.40.tar.xz && \
    tar -xvf binutils-2.40.tar.xz && \
    cd binutils-2.40 && \
    mkdir build && cd build && \
    ../configure --target=$TARGET --prefix=$PREFIX --with-sysroot --disable-nls --disable-werror && \
    make -j$(nproc) && make install

# Install GCC (Cross Compiler)
RUN cd /usr/src/toolchain && \
    curl -O http://ftp.gnu.org/gnu/gcc/gcc-13.1.0/gcc-13.1.0.tar.xz && \
    tar -xvf gcc-13.1.0.tar.xz && \
    cd gcc-13.1.0 && \
    mkdir build && cd build && \
    ../configure --target=$TARGET --prefix=$PREFIX --disable-nls --enable-languages=c --without-headers && \
    make -j$(nproc) all-gcc all-target-libgcc && make install-gcc install-target-libgcc

# Install GDB (Cross Debugger)
RUN cd /usr/src/toolchain && \
    curl -O http://ftp.gnu.org/gnu/gdb/gdb-14.1.tar.xz && \
    tar -xvf gdb-14.1.tar.xz && \
    cd gdb-14.1 && \
    mkdir build && cd build && \
    ../configure --target=$TARGET --prefix=$PREFIX --with-auto-load-safe-path=/usr/local/cross && \
    make -j$(nproc) && make install

# Add cross-compiler to PATH
ENV PATH="$PREFIX/bin:$PATH"

# Set working directory
WORKDIR /usr/src/aetheros

COPY Makefile ./
COPY src/ ./src/
COPY include/ ./include/

COPY . .

CMD ["/bin/bash"]

