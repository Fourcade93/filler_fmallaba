#!/bin/sh

a=40000

if [ $# -gt 0 ]
	then
		a=$1
fi
sed "s|X|$(echo "\033[0;31mX\033[0m")|g" \
| sed "s|O|$(echo "\033[0;34mO\033[0m")|g" \
| ./visualizer $a