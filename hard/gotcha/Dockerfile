FROM ubuntu:18.04
RUN apt-get update && apt-get install -y \
    xinetd \
    && rm -rf /var/lib/apt/lists/*
RUN mkdir -p /home/gotcha && useradd -U gotcha
COPY xinetd /etc/xinetd.d/gotcha
COPY gotcha flag* /home/gotcha/
COPY gotcha /usr/local/bin/
EXPOSE 1337
CMD ["/usr/sbin/xinetd", "-dontfork"]
