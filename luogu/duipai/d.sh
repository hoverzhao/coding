#!/bin/bash
g++ a.hpp -o a -Wall
g++ g.hpp -o g -Wall
g++ b.hpp -o b -Wall
while true;do
	./g > g.in
	./a < g.in > ao
	./b < g.in > bo
	if diff -b -B -q ao bo;then
		echo "AC"
	else
		echo "WA"
		break
	fi
done
