FROM ubuntu:18.04
RUN apt-get update && apt-get install -y \
    xinetd \
    libc6-i386 \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/TEMPLATE && useradd -U TEMPLATE
COPY xinetd /etc/xinetd.d/TEMPLATE
COPY TEMPLATE flag* /home/TEMPLATE/
COPY TEMPLATE /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
