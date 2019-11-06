FROM ubuntu:18.04
RUN apt-get update && apt-get install -y \
    xinetd \
    libc6-i386 \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/multilingual && useradd -U multilingual
COPY xinetd /etc/xinetd.d/multilingual
COPY multilingual flag* /home/multilingual/
COPY multilingual /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
