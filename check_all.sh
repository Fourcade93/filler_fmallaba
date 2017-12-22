#!/bin/sh
rm -f check/*

dir=../resources/players
iam=../test/fmallaba.filler
enemy[0]=abanlin
enemy[1]=carli
enemy[2]=grati
enemy[3]=hcao
enemy[4]=superjeannot
plr=0
while [ $plr -lt 2 ]
do
	en_i=0
	while [ $en_i -lt 5 ]
	do
		if [ $plr -eq 0 ]
			then
				p1=$iam
				p2=$dir/${enemy[$en_i]}.filler
		elif [ $plr -eq 1 ]
			then
				p2=$iam
				p1=$dir/${enemy[$en_i]}.filler
		fi
		map_num=0
		while [ $map_num -lt 3 ]
		do
			a=0
			while [ $a -lt 10 ]
			do
				../resources/./filler_vm -q -p1 $p1 -p2 $p2 -v -f ../resources/maps/map0$map_num >> check/check
				a=`expr $a + 1`
			done
			sed -i.txt -e '/#/g' check/check
			echo "\n\nmap0$map_num\n\n" >> check/check_${enemy[$en_i]}
			grep . check/check >> check/check_${enemy[$en_i]}
			rm -f check/check check/check.txt
			map_num=`expr $map_num + 1`
		done
		en_i=`expr $en_i + 1`
	done
	plr=`expr $plr + 1`
done