FROM ubuntu:18.04
RUN apt-get update && apt-get install -y \
    xinetd \
    libc6-i386 \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/echolocation && useradd -U echolocation
COPY xinetd /etc/xinetd.d/echolocation
COPY echolocation flag* /home/echolocation/
COPY echolocation /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
