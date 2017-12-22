#!/bin/sh
dir=../resources/players
iam=../test/fmallaba.filler
enemy=$dir/carli.filler
p1=$iam
p2=$enemy
if [ $# -eq 4 ]
	then
		if [ $3 -eq 1 ]
			then
				enemy=$dir/abanlin.filler
		elif [ $3 -eq 2 ]
			then
				enemy=$dir/carli.filler
		elif [ $3 -eq 3 ]
			then
				enemy=$dir/champely.filler
		elif [ $3 -eq 4 ]
			then
				enemy=$dir/grati.filler
		elif [ $3 -eq 5 ]
			then
				enemy=$dir/hcao.filler
		elif [ $3 -eq 6 ]
			then
				enemy=$dir/superjeannot.filler
		fi
		if [ $4 -eq 1 ]
			then
				p1=$iam
				p2=$enemy
		elif [ $4 -eq 2 ]
			then
				p1=$enemy
				p2=$iam
		fi
fi
a=0
b=40000
if [ $# -gt 1 ]
	then
		a=$1
		b=$2
fi
make && ../resources/./filler_vm -p1 $p1 -p2 $p2 -v -f ../resources/maps/map0$a | sh visual.sh $b