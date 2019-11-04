FROM ubuntu:18.04
RUN apt-get update && apt-get upgrade && apt-get install -y socat
RUN mkdir -p /home/so-ez && useradd -U so-ez
COPY flag* /
COPY so-ez /usr/local/bin/
EXPOSE 1337
USER so-ez
CMD socat -T10 tcp-listen:1337,reuseaddr,fork exec:/usr/local/bin/so-ez
