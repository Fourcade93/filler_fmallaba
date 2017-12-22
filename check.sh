#!/bin/sh
rm -f check/*
dir=../resources/players
iam=../test/fmallaba.filler
enemy=$dir/carli.filler
p1=$iam
p2=$enemy
if [ $# -eq 2 ]
	then
		if [ $1 -eq 1 ]
			then
				enemy=$dir/abanlin.filler
		elif [ $1 -eq 2 ]
			then
				enemy=$dir/carli.filler
		elif [ $1 -eq 3 ]
			then
				enemy=$dir/champely.filler
		elif [ $1 -eq 4 ]
			then
				enemy=$dir/grati.filler
		elif [ $1 -eq 5 ]
			then
				enemy=$dir/hcao.filler
		elif [ $1 -eq 6 ]
			then
				enemy=$dir/superjeannot.filler
		fi
		if [ $2 -eq 1 ]
			then
				p1=$iam
				p2=$enemy
		elif [ $2 -eq 2 ]
			then
				p1=$enemy
				p2=$iam
		fi
fi
a=0
while [ $a -lt 10 ]
do
	../resources/./filler_vm -q -p1 $p1 -p2 $p2 -v -f ../resources/maps/map00 >> check/check
	a=`expr $a + 1`
done
sed -i.txt -e '/#/g' check/check
grep . check/check > check/check_map00
rm -f check/check

a=0
while [ $a -lt 10 ]
do
	../resources/./filler_vm -q -p1 $p1 -p2 $p2 -v -f ../resources/maps/map01 >> check/check
	a=`expr $a + 1`
done
sed -i.txt -e "/#/g" check/check
grep . check/check > check/check_map01
rm -f check/check

# a=0
# while [ $a -lt 10 ]
# do
# 	../resources/./filler_vm -q -p1 ../test/fmallaba.filler -p2 ../resources/players/carli.filler -v -f ../resources/maps/map02 >> check/check
# 	a=`expr $a + 1`
# done
# sed -i.txt -e "/#/g" check/check
# grep . check/check > check/check_map02
# rm -f check/check