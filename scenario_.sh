#!/bin/bash

ml icc
echo "g++ compilation(0 flag):"
g++ -O Neural.cpp -o test0
time ./test0
echo -e "\n"

echo "g++ compilation(01 flag):"
g++ -O1 Neural.cpp -o test1
time ./test1
echo -e "\n"

echo "g++ compilation(02 flag):"
g++ -O2 Neural.cpp -o test2
time ./test2
echo -e "\n"

echo "g++ compilation(03 flag):"
g++ -O3 Neural.cpp -o test3
time ./test3
echo -e "\n"

echo "g++ compilation(0fast flag):"
g++ -Ofast Neural.cpp -o test4
time ./test4
echo -e "\n"

grep 'flags' /proc/cpuinfo | uniq
echo -e "\n"

extn=(sse2 ssse3 sse4.2 avx)"
for flag in ${extn[@]}
do
icc -std=c++11 -x$flag -O2 Neural.cpp -o nexttest
if [$? -eq 0]
then
echo "Extention $flag"
time ./nexttest
echo -e "\n"
fi
done
