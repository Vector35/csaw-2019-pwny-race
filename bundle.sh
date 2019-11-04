#!/bin/bash
mkdir -p distribute
for dir in easy medium hard
do
    if [ -d $dir ]
    then
        pushd $dir
        for challenge in *
        do
            rm ../distribute/$challenge.zip
            zip ../distribute/$challenge.zip $challenge/xinetd $challenge/$challenge $challenge/Dockerfile $challenge/libc.so.6 $challenge/README
        done
        popd
    fi
done
