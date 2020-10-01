# bminus - a C subset toy compiler

Retargetable C subset compiler. Capable of compiling itself.

Generates linux executable, x86 assembler, C, or javascirpt.

Does not use the C library. No external dependencies, no linking. Uses Linux kernel system calls for I/O.

<br>

## Building and testing in Ubuntu 20.04

install build tools:
```
sudo apt-get install build-essential
sudo apt-get install gcc-multilib
sudo apt-get install nodejs
sudo apt-get install git
```

clone toyrouter repo:
```
git clone "https://github.com/sevenon/toyrouter"
```

build and test:
```
cd toyrouter
make
```
