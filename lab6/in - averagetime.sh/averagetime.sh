#!/bin/bash

echo "enter dictionary file name: "
read dictName
echo "enter grid file name: "
read gridName

r1=`./a.out $dictName $gridName | tail -1`
r2=`./a.out $dictName $gridName | tail -1`
r3=`./a.out $dictName $gridName | tail -1`
r4=`./a.out $dictName $gridName | tail -1`
r5=`./a.out $dictName $gridName | tail -1`

R=$(echo "scale=4; $r1 + $r2 + $r3 + $r4 + $r5" | bc)

averageR=$(echo "scale=0; $R / 5" | bc)

echo $averageR




