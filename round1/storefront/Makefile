.PHONY: docker

storefront: storefront.c Makefile
	gcc -m32 -O2 -o storefront storefront.c -fno-stack-protector -fomit-frame-pointer -zexecstack

docker: storefront Dockerfile
	docker image build -t storefront:latest .
