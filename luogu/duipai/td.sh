#!/bin/bash
g++ a.cpp -o a -Wall
g++ b.cpp -o b -Wall
g++ g.cpp -o g -Wall
while true;do
	./g > g.in 
	./a < g.in > a.out
	./b < g.in > b.out
	if diff -b -B  a.out b.out;then
		echo "AC"
	else
		echo "WA"
		break
	fi
done

