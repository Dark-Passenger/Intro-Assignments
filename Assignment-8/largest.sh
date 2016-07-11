#!/bin/bash

echo "Enter first number : "
read a
echo "Enter second number : "
read b
echo "Enter third number : "
read c

largest=$a
if [ $b -gt $largest ]
then
largest=$b
fi
if [ $c -gt $largest ]
then
largest=$c
fi
echo "Largest of $a $b $c is $largest"
