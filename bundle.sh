#!/bin/bash
for dir in easy medium hard
do
    if [ -d $dir ]
    then
        pushd $dir
        for challenge in *
        do
            zip ../distribute/$challenge.zip $challenge/xinetd $challenge/$challenge $challenge/Dockerfile $challenge/README
        done
        popd
    fi
done
