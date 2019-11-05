FROM ubuntu:18.04
RUN apt-get update && apt-get install -y \
    xinetd \
    libc6-i386 \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/storefront && useradd -U storefront
COPY xinetd /etc/xinetd.d/storefront
COPY storefront flag* /home/storefront/
COPY storefront /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
