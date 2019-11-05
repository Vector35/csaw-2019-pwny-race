.PHONY: docker

kernel: kernel.c Makefile
	gcc -m32 -O2 -o kernel kernel.c -fomit-frame-pointer -D_FORTIFY_SOURCE=0

docker: kernel Dockerfile
	docker image build -t kernel:latest .
