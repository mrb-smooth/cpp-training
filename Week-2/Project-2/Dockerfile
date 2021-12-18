FROM ubuntu:20.04

# Set env to avoid user input interruption during installation
ENV TZ=America/Chicago
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

# Install normal goodies
RUN apt-get update -y
RUN apt-get install -y --no-install-recommends ssh \
                                               sudo \
                                               zsh \
                                               zsh-autosuggestions \
                                               git \
                                               curl \
                                               wget \
                                               libtool \
                                               vim \
                                               tree \
                                               zip \
                                               unzip \
                                               autoconf \
                                               automake \
                                               build-essential \
                                               pkg-config \
                                               make \
                                               clang \
                                               gdb \
                                               cscope \
                                               htop \
                                               iftop \
                                               iotop

# Change login shell to zsh
RUN chsh -s /bin/zsh $(whoami)

# Copy profile
COPY .profile /root/.profile
COPY .vimrc /root/.vimrc
COPY .zshrc /root/.zshrc

# Set compiler variables
ENV CC=/bin/clang
ENV CXX=/bin/clang++

# Install dependencies
RUN mkdir -p /tmp/protobuf-cpp
RUN cd /tmp/protobuf-cpp && \
    wget --no-check-certificate https://github.com/protocolbuffers/protobuf/releases/download/v3.19.1/protobuf-cpp-3.19.1.zip && \
    unzip protobuf-cpp-3.19.1.zip && \
    cd protobuf-3.19.1 && \
    ./configure && \
    make -j$(nproc) && \
    make install && \
    sudo ldconfig

# Spew nonsense
CMD ["echo", "run './root/setup.sh --all' setup the base environment"]
