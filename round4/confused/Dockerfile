FROM ubuntu:18.04
RUN apt-get update && apt-get install -y \
    xinetd \
    libc6-i386 \
    lib32stdc++6 \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/confused && useradd -U confused
COPY xinetd /etc/xinetd.d/confused
COPY confused flag* /home/confused/
COPY confused /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
