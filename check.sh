#!/bin/sh
rm -f check/*
a=0
while [ $a -lt 10 ]
do
	../resources/./filler_vm -q -p1 ../test/fmallaba.filler -p2 ../resources/players/carli.filler -v -f ../resources/maps/map00 >> check/check
	a=`expr $a + 1`
done
sed -i.txt -e '/#/g' check/check
grep . check/check > check/check_map00
rm -f check/check

a=0
while [ $a -lt 10 ]
do
	../resources/./filler_vm -q -p1 ../test/fmallaba.filler -p2 ../resources/players/carli.filler -v -f ../resources/maps/map01 >> check/check
	a=`expr $a + 1`
done
sed -i.txt -e "/#/g" check/check
grep . check/check > check/check_map01
rm -f check/check

a=0
while [ $a -lt 10 ]
do
	../resources/./filler_vm -q -p1 ../test/fmallaba.filler -p2 ../resources/players/carli.filler -v -f ../resources/maps/map02 >> check/check
	a=`expr $a + 1`
done
sed -i.txt -e "/#/g" check/check
grep . check/check > check/check_map02
rm -f check/check