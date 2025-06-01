+++
title = "CMake Workshop for Elbit-Elisra"
+++

# About Me

Hi! I'm Alex Kushnir, and I will be guiding you through this CMake workshop. This page will help you to get ready for our time together and will save us time to talk about really important things!

---

# Workshop Syllabus

- Introduction to CMake
- CMake language basics 
- Setting up a CMake project
- CMake targets
- C++ compilation and linking using CMake 
- Managing dependencies with CMake 
- Unit testing with CMake 
- Program analysis tools
- Installation and packaging (optional)
- Writing CMake presets

---

# Setup the environment
When I was preparing the workshop, I wrote the supporting code in VSCode with WSL plugin installed, I worked with WSL, CMake 3.28 and gcc 14.2. Below is the command I had to run to install all needed packages.
- OS - I was using Ubuntu inside WSL container, but most of the examples are OS-agnostic (there are some examples that demonstrate working cross-platform or platform-specific tweaks).
- Packages needed - can be taken from the Dockerfile, it is the same list. Pay attention that the "universe" apt repository should be added in order to install gcc-14
- IDE - I used VSCode with WSL plugin installed 
- CMake - every modern version should suffice, I was using 3.28 - the version from Ubuntu apt repository
- Compiler - every compiler supporting C++23 (I used gcc 14.2, 99% of the supporting code assumes it).

## Packages to install 

- Update the packages index on your system by running sudo apt-get update
- Install the following packages (apt-get install -y ...)
	- wget 
	- ca-certificates 
	- gnupg2 
	- software-properties-common 
	- build-essential 
	- vim 
	- zsh 
	- tree 
	- git 
	- lcov 
	- gawk 
	- file 
	- gdb 
	- python-is-python3 
	- python3-pip pipx
	- g++ 
	- make 
	- ninja-build 
	- cmake
	- gcc-13-arm-linux-gnueabi 
	- g++-13-arm-linux-gnueabi 
	- pkg-config 
	- valgrind 
	- doxygen 
	- graphviz 
	- cppcheck 
	- libboost-all-dev 
	- libpqxx-dev 

	Full command: ```sudo apt-get update && apt-get install --no-install-recommends -y wget ca-certificates gnupg2 software-properties-common build-essential vim zsh tree git lcov gawk file gdb python-is-python3 python3-pip pipx g++ make ninja-build cmake gcc-13-arm-linux-gnueabi g++-13-arm-linux-gnueabi pkg-config valgrind doxygen graphviz cppcheck libboost-all-dev libpqxx-dev```
	
- Add the "universe" apt repository by typing ```add-apt-repository universe```
- Then, update the package index by typing ```apt-get update```
	- Install gcc-14 and g++14
Full command: ```add-apt-repository universe && apt-get update && apt-get install --no-install-recommends -y gcc-14 g++-14```

- Set the default commands to point to the latest gcc and g++ versions 
	- ```update-alternatives --install /usr/bin/arm-linux-gnueabi-gcc arm-linux-gnueabi-gcc /usr/bin/arm-linux-gnueabi-gcc-13 10```
	- ```update-alternatives --install /usr/bin/arm-linux-gnueabi-g++ arm-linux-gnueabi-g++ /usr/bin/arm-linux-gnueabi-g++-13 10```
	- ```update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 10```
	- ```update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-14 10```

- Install conan 
	- ```pipx install conan ```
	- ```pipx ensurepath```
	- ```conan profile detect --force```

# Support code for the Workshop
All code is stored in github repository ```[https://github.com/alexkushnir/cmake_course](https://github.com/alexkushnir/cmake_course)```

# Docker Image Installation

To get started quickly, use a pre-configured docker image in one of 2 ways:

- Build the image locally using the Dockerfile from the github repo - ```[https://github.com/alexkushnir/cmake_course/blob/master/Dockerfile](https://github.com/alexkushnir/cmake_course/blob/master/Dockerfile)```
	- ```docker build -t cmake-workshop . ```(Assuming running from the same folder where the Dockerfile is)
	- ```docker run -it --rm -v <local-dir>:/mnt cmake-workshop```
- Pull the image from Dockerhub
	- ```docker pull alexkushnir1/cmake-workshop:latest```
	- ```docker run -it --rm -v <local-dir>:/mnt alexkushnir1/cmake-workshop:latest```

This image contains all necessary tools pre-installed.

---

# Simple Testing Exercise

Try the following simple exercise to test your setup:
After logging in, type the following:\
```cmake -S 01_intro/ -B build && cmake --build build && build/01_intro```

If everything is fine, you should see something like that: \
```-- The C compiler identification is GNU 14.2.0 \
-- The CXX compiler identification is GNU 14.2.0 \
-- Detecting C compiler ABI info \
-- Detecting C compiler ABI info - done\
-- Check for working C compiler: /usr/bin/cc - skipped \
-- Detecting C compile features \
-- Detecting C compile features - done \
-- Detecting CXX compiler ABI info \
-- Detecting CXX compiler ABI info - done \
-- Check for working CXX compiler: /usr/bin/c++ - skipped \
-- Detecting CXX compile features \
-- Detecting CXX compile features - done \
-- Configuring done (0.5s) \
-- Generating done (0.0s) \
-- Build files have been written to: /devuser/build \
[ 50%] Building CXX object CMakeFiles/01_intro.dir/hello.cpp.o \
[100%] Linking CXX executable 01_intro \
[100%] Built target 01_intro ```
 
```Hello, World! ```

