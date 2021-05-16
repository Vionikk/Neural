#!/bin/bash
ml icc
grep 'flags' /proc/cpuinfo | uniq
echo -e "\n"
extn=(sse2 ssse3 sse4.2 avx)
for flag in ${extn[@]}
do
icc -std=c++11 -x$flag -O2 Neural_v2.cpp -o nexttest
if [ $? -eq 0 ]
then
echo "Extension: $flag"
time ./nexttest
echo -e "\n"
fi
done
