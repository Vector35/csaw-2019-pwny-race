#!/bin/bash
mkdir -p distribute
for dir in round1 round2 round3 tiebreaker
do
    if [ -d $dir ]
    then
        pushd $dir
        for challenge in *
        do
            rm ../distribute/$challenge.zip
            pwd
            echo ../distribute/$challenge.zip
            zip ../distribute/$challenge.zip $challenge/xinetd $challenge/$challenge $challenge/Dockerfile $challenge/libc.so.6 $challenge/README
        done
        popd
    fi
done
