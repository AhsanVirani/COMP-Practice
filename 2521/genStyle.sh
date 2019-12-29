#!/bin/sh
files="lec tute prac lab"
i=5
while test $i -lt 9
do
	while test "" == $files
	do
		echo $files | cut
		$files=$(cut -d' ' -f2-..)
	done
	i=$(expr $i + 1)
done

