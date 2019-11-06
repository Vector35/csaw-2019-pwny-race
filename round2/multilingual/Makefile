.PHONY: docker

multilingual: multilingual.c Makefile
	gcc -O0 -o multilingual multilingual.c 
	strip multilingual

docker: multilingual Dockerfile
	docker image build -t multilingual:latest .
