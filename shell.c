#!/bin/bash
echo "Hello, World!"

Program 1:
#!/bin/sh
a=10
b=10
#b=20
if [ $a -eq $b ]
then
echo "a is equal to b"
else
echo "a is not equal to b"
fi

Program 2:
#!/bin/bash
for (( c=1 ; c<=5 ; c++ ))
do
echo "Welcome $c times"
Done

Program 3:
#!/bin/sh
echo "Enter Your Nmae"
read person
echo "Hello $person"

Program 4:
#!/bin/sh
echo "Shell name is $SHELL"
echo "home directory is $HOME"
echo "Current DIrectory is $PWD"
echo "bash version is $BASH_VERSION"

program 5 :

# !/bin/bash
 
# Take user Input
echo "Enter Two numbers : "
read a
read b
 
# Input type of operation
echo "Enter Choice :"
echo "1. Addition"
echo "2. Subtraction"
echo "3. Multiplication"
echo "4. Division"
read ch
 
# Switch Case to perform
# calculator operations
case $ch in
  1)res=`echo $a + $b | bc`
  ;;
  2)res=`echo $a - $b | bc`
  ;;
  3)res=`echo $a \* $b | bc`
  ;;
  4)res=`echo "scale=2; $a / $b" | bc`
  ;;
esac
echo "Result : $res"
