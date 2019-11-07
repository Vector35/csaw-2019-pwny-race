.PHONY: docker

murica: murica.c Makefile
	gcc -m32 -O0 -o murica murica.c

docker: murica Dockerfile
	docker image build -t murica:latest .

america_great_again:
	@echo lol
	@exit
