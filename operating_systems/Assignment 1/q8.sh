#!/bin/bash

if [ -d $1 ]
then
	echo "Yes, Its a directory"
elif [ -r $1 ]
then
	echo "File is a readable file"
elif [ -w $1 ]
then 
	echo "File is a writable file"
elif [ -x $1 ]
then
	echo "File is an executable file"
fi
