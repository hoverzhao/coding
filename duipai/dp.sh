#!/bin/bash
g++ a.cpp -o a -Wall 
g++ b.cpp -o b -Wall
g++ g.cpp -o g -Wall

while true;do
	./g > t.in
	./a < t.in > a.out
	./b < t.in > b.out
	if diff -b -B a.out b.out;then
		echo "AC"
	else
		echo "WA"
		break
	fi
done
