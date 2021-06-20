#!/bin/bash

# $RANDOM returns a different random integer at each invocation.
# Nominal range: 0 - 32767 (signed 16-bit integer).

count=1

echo  "Enter number"
read MAXCOUNT

while [ "$count" -le $MAXCOUNT ]      # Generate 10 ($MAXCOUNT) random integers.
do
  number=$RANDOM
  echo -n $number
  echo -n " "
  let "count += 1"  # Increment count.
done
