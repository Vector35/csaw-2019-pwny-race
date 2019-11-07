.PHONY: docker

roplecoptor: roplcopter.c Makefile
	gcc -m32 -static -s -O0 -o roplcopter roplcopter.c -fno-stack-protector -no-pie -fno-pie -fomit-frame-pointer

docker: roplcopter Dockerfile
	docker image build -t roplcopter:latest .
