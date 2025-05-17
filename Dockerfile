FROM ubuntu:latest

# Install any necessary tools
RUN apt-get update && apt-get install -y \
    git \
    curl \
    build-essential \
	cmake \
	gcc-13-arm-linux-gnueabi \ 
	g++-13-arm-linux-gnueabi \
	graphviz \
    # add more tools if needed
    && rm -rf /var/lib/apt/lists/*

# Clone the GitHub repository
RUN git config --global http.sslVerify false
RUN git clone https://github.com/alexkushnir/cmake_course.git /cmake_course

# Set the default command to run when starting the container
CMD ["bash"]
