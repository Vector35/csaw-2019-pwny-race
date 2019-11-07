.PHONY: docker

fourmatts: fourmatts.c Makefile
	gcc -m32 -O2 -o fourmatts fourmatts.c -Wl,-z,norelro -D_FORTIFY_SOURCE=0

docker: fourmatts Dockerfile
	docker image build -t fourmatts:latest .
