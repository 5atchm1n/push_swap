#!/bin/bash

MAXCOUNT=10

count=1
avg=0
echo "3 stack -- running 10 tests"
while [ "$count" -le $MAXCOUNT ]
do
	ARG=`ruby -e "puts (1..3).to_a.shuffle.join(' ')"`;
	echo $ARG
	./push_swap $ARG
	let "count += 1"
done


# AVERAGE MOVES FOR 100 stacks
MAXCOUNT=100
count=1
avg=0
echo "5 stack -- running 100 tests"
while [ "$count" -le $MAXCOUNT ]
do
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`;
	TOT=`./push_swap $ARG | wc -l`
	avg=$((avg+TOT))
	let "count += 1"
done

avg=$((avg/MAXCOUNT))
echo "Average move count is :"
echo $avg

# AVERAGE MOVES FOR 100 stacks
MAXCOUNT=100
count=1
avg=0
echo "100 stack -- running 100 tests"
while [ "$count" -le $MAXCOUNT ]
do
	ARG=`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`;
	TOT=`./push_swap $ARG | wc -l`
	avg=$((avg+TOT))
	let "count += 1"
done

avg=$((avg/MAXCOUNT))
echo "Average move count is :"
echo $avg

# AVERAGE MOVES FOR 500 stacks
count=1
avg=0

echo "500 stack -- running 100 tests"
while [ "$count" -le $MAXCOUNT ]
do
	ARG=`ruby -e "puts (0..499).to_a.shuffle.join(' ')"`;
	TOT=`./push_swap $ARG | wc -l`
	avg=$((avg+TOT))
	let "count += 1"
done

avg=$((avg/MAXCOUNT))
echo "Average move count is :"
echo $avg
