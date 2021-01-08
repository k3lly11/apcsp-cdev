#!/bin/bash

PROGARR=(variables sizeofvariables ifstmnt iteration)

if [ $# -ne 0 ] ; then
    for PROG in "${PROGARR[@]}" ; do
	rm $PROG &>/dev/null
    done
    echo "cleaned up"
    exit 0
fi

for PROG in "${PROGARR[@]}" ; do
    if [ -e $PROG.c ] ; then
	gcc $PROG.c -o $PROG
	if [ $? -ne 0 ] ; then
	    echo "build error: "$PROG
	    exit $?
	fi
    fi
done
echo "built all"
