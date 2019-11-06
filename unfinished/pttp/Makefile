.PHONY: docker

pttp: pttp.cc Makefile
	g++ -std=gnu++11 -m32 -O2 -o pttp pttp.cc -no-pie -fno-pie -fomit-frame-pointer

docker: pttp Dockerfile
	docker image build -t pttp:latest .
