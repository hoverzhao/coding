#!/bin/bash
g++ a.cpp -o a -Wall -std=c++11
g++ b.cpp -o b -Wall -std=c++11
g++ g.cpp -o g -Wall -std=c++11

while true;do
	./g > t.in
	./a < t.in > a.oo
	./b < t.in > b.oo
	if diff -b -B a.oo b.oo;then
		echo "AC"
	else
		echo "WA"
		cp t.in in.txt
		break
	fi
done

