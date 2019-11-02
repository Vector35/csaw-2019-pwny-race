#!/bin/bash

function error {
    echo "$0 <easy|medium|hard> challengename"
    exit 1
}

if [ $# -ne 2 ]
then
    error;
fi

case $1 in
    easy|medium|hard)
    ;;
    *)
        error
    ;;
esac

echo Creating $1/$2
mkdir -p $1/$2
pushd template
for file in Dockerfile Makefile README flag solution.py xinetd
do
    sed "s/TEMPLATE/$2/g" < $file > ../$1/$2/$file
done
cp template.c ../$1/$2/$2.c
popd
