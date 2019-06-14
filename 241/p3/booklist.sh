#!/bin/bash
clear

if test "$#" -ne 1; then
	echo "Not enough command line parameters. Enter filename" 1>&2
        exit 1
fi
if [ ! -e $1 ]; then
	echo "$1 does not exist!" 1>&2
	exit 1
fi
if [ ! -r "$1" ]; then
        echo "$1 is not readable "
	exit 1
fi
if [ ! -w "$1" ]; then
	echo "$1 is not modifiable "
	exit 1
fi

file="$1"
choice=0
echo "1: Search by author "
echo "2: New entry "
echo "3: Delete entry by title "
echo "4: Display all entries "
echo "5: Exit "

while [ "$choice" -ne 5 ]
do
	echo "= Enter choice # = "
  	read choice
  	case $choice in
		1) 
			echo "Enter author to search: "
			read aut
			grep "$aut" $file
			;;
		2)
			echo "Enter author:title:year "
			read ent
			if grep -Fxq "$ent" $file
			then
				echo "This entry already exists... "
			else
				echo "$ent" >> $file
			fi
			;;
		3)
			echo "Enter title to delete: "
			read tit
			if grep -q ":$tit:" $file
			then	
				grep -v ":$tit:" $file > zz
				rm $file
				mv zz $file
			else 
				echo "Entry does not exist "
			fi
			;;
		4)
			sort -k2 proj3.txt | gawk -F: '{printf "%s\t%s\t%s\n", $1, $2, $3}' $file
			echo -n "Total:     " ; wc -l < $file
			;;
		5)
			exit 0
			;;
	esac
done