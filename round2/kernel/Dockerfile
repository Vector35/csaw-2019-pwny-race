FROM ubuntu:18.04
RUN apt-get update && apt-get install -y \
    xinetd \
    libc6-i386 \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/kernel && useradd -U kernel
COPY xinetd /etc/xinetd.d/kernel
COPY kernel flag* /home/kernel/
COPY kernel /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
