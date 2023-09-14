#!/bin/bash                                                                     
                                                                                
echo "enter the exponent for counter.cpp: "
read exp

if [ $exp == quit ]
then
    exit
else
    sum=0

    for i in 1 2 3 4 5
    do
	echo "Running iteration $i..."
	r=`./a.out $exp | tail -1`
	echo "time taken: " $r
	sum=$((sum+r))
    done
    
    echo "5 iterations took "$sum" ms"                                                                           
    averageR=$(echo "scale=0; $sum / 5" | bc)                                         
    
    echo "Average time was "$averageR" ms"
fi

                
