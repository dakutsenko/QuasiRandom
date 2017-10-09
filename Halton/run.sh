#!/bin/bash
echo 100 | ./halton > data.txt
if [ $? == 0 ]
then
	if [ $TERM != 'linux' ]
	then
		gnuplot -p -e 'plot "data.txt"'
	else
		gnuplot -p -e 'set t dumb; plot "data.txt"'
	fi
fi
