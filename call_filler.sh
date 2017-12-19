#!/bin/sh
a=0
b=40000
if [ $# -eq 2 ]
	then
		a=$1
		b=$2
fi
make && ../resources/./filler_vm -p1 ../test/fmallaba.filler -p2 ../resources/players/carli.filler -v -f ../resources/maps/map0$a | sh visual.sh $b