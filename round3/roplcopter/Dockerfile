FROM ubuntu:18.04
RUN apt-get update && apt-get install -y \
    xinetd \
    libc6-i386 \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/roplcopter && useradd -U roplcopter
COPY xinetd /etc/xinetd.d/roplcopter
COPY roplcopter flag* /home/roplcopter/
COPY roplcopter /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
