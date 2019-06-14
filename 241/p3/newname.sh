#!/bin/bash
clear

if test "$#" -ne 2; then
	echo "Not enough command line parameters" 1>&2
        exit 1
fi

if [ ! -e $1 ] ; then
	echo "$1 does not exist!" 1>&2
	exit 1
fi

num=0
fname=$2

while test -f "$fname"
do
	let num=num+1 
	fname=$2.$num
done
mv $1 $fname