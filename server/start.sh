#!/bin/sh

docker build -t csaw_pwny_race_server .
if [ "$(docker ps -aq -f name=csaw_pwny_server)" ]; then
    docker kill csaw_pwny_server;
    docker rm csaw_pwny_server;
fi
docker run --name csaw_pwny_server -p 80:80 -d csaw_pwny_race_server
