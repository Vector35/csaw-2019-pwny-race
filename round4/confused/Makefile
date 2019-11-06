.PHONY: docker

confused: confused.cpp Makefile
	g++ -m32 -O2 -o confused confused.cpp

docker: confused Dockerfile
	docker image build -t confused:latest .
