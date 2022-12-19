# Dockerfile for PDR, from https://github.com/uva-cs/pdr
# This file can be found at:
# https://github.com/uva-cs/pdr/blob/master/tutorials/01-intro-unix/Dockerfile
#
# Run with:
# docker build --no-cache -t pdr:latest .
#
# if using an APT proxy, run with:
# docker build --no-cache -t pdr:latest --build-arg APT_PROXY=<apt_proxy_ip> .


FROM ubuntu:20.04
LABEL maintainer="Aaron Bloomfield aaron@virginia.edu"
ENV DEBIAN_FRONTEND noninteractive

# step 1: set up the apt proxy (if using one), and upgrade the system
ARG APT_PROXY=0.0.0.0
RUN echo $APT_PROXY | grep -v 0.0.0.0 | awk '{print "Acquire::http::Proxy \"http://" $1 ":3142\";"}' > /etc/apt/apt.conf.d/02proxy && \
    apt-get update -y -q -q && \
    apt-get dist-upgrade -y -q -q

# step 2: install everything that's needed; this can be cut-and-pasted
# into other Dockerfiles
# --------------- CUT HERE ---------------
RUN apt-get update -y -q -q && \
    apt-get install -y -q -q --no-install-recommends locales apt-utils && \
    locale-gen en_US.UTF-8 && \
    apt-get install -y -q -q --no-install-recommends clang llvm emacs vim nasm astyle tofrodos source-highlight gdb lldb doxygen doxygen-doc graphviz ddd git g++ gobjc gnustep gnustep-make gnustep-common libgnustep-base-dev evince g++-multilib libc6-dev-i386 libc6-dev flex make && \
    update-alternatives --set cc /usr/bin/clang && \
    update-alternatives --set c++ /usr/bin/clang++ && \
    update-alternatives --install /usr/bin/llvm-symbolizer llvm-symbolizer /usr/bin/llvm-symbolizer-10 1000 && \
    touch /root/.bash_aliases && \
    echo "alias mv='mv -i'" >> /root/.bash_aliases && \
    echo "alias rm='rm -i'" >> /root/.bash_aliases && \
    echo "alias cp='cp -i'" >> /root/.bash_aliases && \
    git clone https://github.com/uva-cs/pdr /root/pdr && \
    apt-get clean -y
# --------------- CUT HERE ---------------

# step 3: clean up!
RUN /bin/rm -f /etc/apt/apt.conf.d/02proxy && \
    apt-get update -y -q -q
