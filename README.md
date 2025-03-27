# AetherOS

**AetherOS** is an open-source operating project that started as an academic endeavor to explore the inner workings of operating systems, with a focus on building a custom kernel and implementing essential OS functionalities from the ground up.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Build Instructions](#build-instructions)
  - [Running AetherOS](#running-aetheros)
- [Future Features](#future-features)
- [Contributing](#contributing)
- [License](#license)

## About

AetherOS is being developed as part of a learning initiative to gain a deeper understanding of system internals, including memory management, interrupt handling, bootstrapping, and low-level hardware interaction. This project is implemented in **C**, and aims to serve as a basic kernel with potential expansions into more advanced OS features. While it is still in early development, it provides an opportunity to study operating system construction in detail.

### Academic Focus

The primary goal of AetherOS is educational — the project is intended to help the developer (and anyone who reads the code) gain practical experience in building operating system components. As an academic project, AetherOS does not aim to be a fully-featured or production-ready OS but rather a learning tool for understanding the foundational concepts.

## Features

- **Bootstrapping Process:** Custom bootloader written in assembly.
- **Basic Kernel:** Implementing a rudimentary kernel with memory management, interrupts, and simple device drivers.
- **x86_64 Architecture Support:** The current target architecture is x86_64.

## Getting Started

To begin developing and experimenting with AetherOS, you'll need to build and run it in a Dockerized development environment. Here's how to get started.

### Prerequisites

Before building AetherOS, ensure you have the following prerequisites installed:

- Docker
- Docker Compose (optional but recommended)

### Build Instructions

1. Clone this repository to your local machine:
   ```bash
   git clone https://github.com/TravisBubb/AetherOS.git
   cd AetherOS
   ```
2. Build the Docker image (this step will install necessary dependencies and setup the cross-compilation toolchain, so it may take a few minutes):
    ```bash
    docker-compose build
    ```
3. Once the image is built, you can compile the operating system kernel using the provided docker-make script:
    ```bash
    ./docker-make.sh
    ```

### Running AetherOS

You can run AetherOS using QEMU, which is a system emulator. The provided scripts/run.sh script can be used to boot the kernel image in QEMU:
    ```bash
    ./scripts/run.sh
    ```

### Debugging

For debugging you can use GDB with QEMU:

1. Build the kernel with debugging symbols enabled:
    ```bash
    ./docker-make.sh debug
    ```
2. Start QEMU in GDB server mode:
    ```bash
    ./scripts/debug.sh
    ```

### Future Features

While AetherOS is currently a *very* simple OS project, several features are planned for future development:
- **Memory Management**: Implement a robust memory allocator, paging, and virtual memory
- **Process Scheduling**: Build a basic scheduler to handle multitasking
- **File System Support**: Implement a basic file system for persistent storage
- **Device Drivers**: Expand device support, including networking, storage, and more
- **User-Space Programs**: Introduce user-mode applications that interact with the kernel

### Contributing

Since this is a personal learning project, at this point in time, contributions are welcome in the form of feedback, bug reports, or suggestions for improvement. Given that the project is primarily educational, it is not intended for widespread production use.

If you wish to contribute, feel free to fork the repository, create an issue, or submit a pull request with your improvements.

### License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/TravisBubb/aether-os/blob/main/LICENSE) file for details.
