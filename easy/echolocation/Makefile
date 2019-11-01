.PHONY: docker

echolocation: echolocation.c Makefile
	gcc -m32 -O2 -o echolocation echolocation.c -fno-stack-protector -no-pie -fno-pie -fomit-frame-pointer

docker: echolocation Dockerfile
	docker image build -t echolocation:latest .
