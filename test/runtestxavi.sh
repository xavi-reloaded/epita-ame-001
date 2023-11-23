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

echo ""
echo -e "${BIRed}=== (${IGreen}1${BIRed}) play with strings === [ ${BICyan} xavi_strings_test.c ${BIRed} ] ${NC} "
gcc -o test xavi_strings_test.c ../src/http/http.c ${EXTRA_FLAGS} -lcriterion
./test
echo -e "${BIRed}===================================================================${NC} "
echo ""

rm test