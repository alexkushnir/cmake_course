FROM ubuntu:latest AS build-env

RUN apt-get update && \
    apt-get install --no-install-recommends -y wget ca-certificates gnupg2 software-properties-common \
    build-essential vim zsh tree git lcov gawk file gdb python-is-python3 python3-pip pipx tree\
    g++ make ninja-build cmake clang-format\
    gcc-13-arm-linux-gnueabi g++-13-arm-linux-gnueabi \
    pkg-config valgrind doxygen graphviz cppcheck \
    libboost-all-dev libpqxx-dev \
    && rm -rf /var/lib/apt/lists/*

RUN update-alternatives --install /usr/bin/arm-linux-gnueabi-gcc arm-linux-gnueabi-gcc /usr/bin/arm-linux-gnueabi-gcc-13 10
RUN update-alternatives --install /usr/bin/arm-linux-gnueabi-g++ arm-linux-gnueabi-g++ /usr/bin/arm-linux-gnueabi-g++-13 10

RUN add-apt-repository universe && apt-get update && apt-get install --no-install-recommends -y gcc-14 g++-14

RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-14 10
RUN update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-14 10

RUN pipx install conan
RUN pipx ensurepath
RUN echo "conan profile detect --force" >> ~/.bashrc

RUN chsh -s /bin/bash

FROM build-env AS devcontainer
RUN apt-get update && apt-get install -y openssh-server sudo && rm -rf /var/lib/apt/lists/*
RUN useradd -m devuser && echo 'devuser:devuser' | chpasswd && adduser devuser sudo
RUN mkdir /var/run/sshd
RUN echo 'PermitRootLogin no' >> /etc/ssh/sshd_config && echo 'PasswordAuthentication yes' >> /etc/ssh/sshd_config
RUN echo 'PermitUserEnvironment yes' >> /etc/ssh/sshd_config
EXPOSE 22
CMD ["/usr/sbin/sshd", "-D"]

RUN git config --global http.sslVerify false
RUN git clone https://github.com/alexkushnir/cmake_course.git /devuser

FROM devcontainer AS examples
WORKDIR /devuser
CMD ["/bin/bash"]
