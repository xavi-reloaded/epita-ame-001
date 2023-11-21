#!/bin/bash

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)    EXTRA_FLAGS="-I/opt/homebrew/include -L/opt/homebrew/lib";;
    *)          EXTRA_FLAGS=""
esac


# NOTE : Quote it else use array to avoid problems #
FILES="*test.*"
for f in $FILES
do
  echo "RUNNING TEST ${f}"
  gcc -o test ${f} ${EXTRA_FLAGS} -lcriterion
./test
done



