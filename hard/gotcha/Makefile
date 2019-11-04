.PHONY: docker

gotcha: gotcha.c Makefile
	gcc -O2 -o gotcha gotcha.c -Wl,-z,norelro
	strip gotcha

docker: gotcha Dockerfile
	docker image build -t gotcha .
