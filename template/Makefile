.PHONY: docker

TEMPLATE: TEMPLATE.c Makefile
	gcc -m32 -O2 -o TEMPLATE TEMPLATE.c -fno-stack-protector -no-pie -fno-pie -fomit-frame-pointer

docker: TEMPLATE Dockerfile
	docker image build -t TEMPLATE:latest .
