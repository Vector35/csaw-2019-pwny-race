FROM ubuntu:18.04

RUN apt update
RUN apt install -y python3 python3-pip gunicorn3 nginx

RUN service nginx start

RUN rm /etc/nginx/sites-enabled/default

RUN mkdir /raceserv
WORKDIR /raceserv

COPY nginx-csaw.conf /etc/nginx/sites-enabled/nginx-csaw.conf

RUN useradd -m webmaster
RUN chown -R webmaster:webmaster /raceserv
USER webmaster

RUN pip3 install --user django

COPY server .

RUN python3 manage.py makemigrations && python3 manage.py migrate
RUN python3 manage.py collectstatic --noinput

USER root
CMD service nginx start &&  su -c "gunicorn3 --bind 0.0.0.0:8000 server.wsgi" webmaster
