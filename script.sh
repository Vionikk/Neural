#!/bin/bash   
        ml icc
	echo “AMENO”
	echo “Optimization O1”
	icc -restrict -O1 Neural.cpp -o simp1 
	time ./ Neural.cpp                                                                                                                 
	echo “Optimization O2”	
	icc -restrict -O2 -qopt-report=2 -qopt-report-phase=vec -D NOALIAS Neural.cpp -o simpvec2     
	time ./ Neural.cpp                                                         
	echo “Optimization O3”
	icc -restrict -O3 -qopt-report=3 -qopt-report-phase=vec -D NOALIAS Neural.cpp -o simpvec3
	time ./ Neural.cpp
	echo “YESSSS”
	
	cflis=`grep "flags" /proc/cpuinfo | head -1 | cut -d':' -f2 | cut -d" " -f2- | tr _ . | tr "a-z" "A-Z"