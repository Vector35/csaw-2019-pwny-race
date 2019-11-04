.PHONY: docker

so-ez: so-ez.c Makefile
	gcc -m64 -O2 -o so-ez so-ez.c -fno-stack-protector -no-pie -fno-pie -fomit-frame-pointer

docker: so-ez Dockerfile
	docker image build -t so-ez:latest .
