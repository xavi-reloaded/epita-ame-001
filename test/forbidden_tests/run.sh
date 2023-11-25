#!/bin/bash

NC='\033[0m' # No Color
IGreen='\033[0;92m'
BICyan='\033[1;96m' 
BIRed='\033[1;91m'

unameOut="$(uname -s)"
case "${unameOut}" in
    Darwin*)    EXTRA_FLAGS="-I/opt/homebrew/include -L/opt/homebrew/lib";;
    *)          EXTRA_FLAGS=""
esac

for f in ./*.c
do
    chmod -rx ../test_files/root/access_forbidden.txt # write desired permissions
	echo "Processing $f"
    echo ""
    echo -e "${BIRed}=== (${IGreen}1${BIRed}) Forbbiden Tests === [ ${BICyan} ${f} ${BIRed} ] ${NC} "
    gcc -o test ${f}  ../../src/http/rules.c ../../src/http/http.c ${EXTRA_FLAGS} -lcriterion
    ./test
    echo -e "${BIRed}===================================================================${NC} "
    echo ""
    rm test
    chmod +rx ../test_files/root/access_forbidden.txt # restore desired permissions
done

