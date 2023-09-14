#!/bin/bash

echo > ./test/output

cat ./test/cases | while read line
do
	if [[ ${line:0:1} == '#' ]]; then
		echo $line >> ./test/output
	else
		echo $line >> ./test/output
		#./philo $line >> ./test/output
	fi
done