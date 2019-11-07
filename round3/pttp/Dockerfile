FROM ubuntu:18.04
RUN dpkg --add-architecture i386
RUN apt-get update && apt-get install -y \
    xinetd \
    libc6:i386 libstdc++6:i386 \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/pttp && useradd -U pttp
COPY xinetd /etc/xinetd.d/pttp
COPY pttp flag* /home/pttp/
COPY pttp /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
