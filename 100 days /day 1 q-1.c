//Q1: Write a program to input two numbers and display their sum.

/*
Sample Test Cases:
Input 1:
3 4
Output 1:
Sum = 7

Input 2:
-1 20
Output 2:
Sum = 19

*/

#include<stdio.h>
void main()
{
    int a,b,c;
    printf("Enter 2 numbers : ");
    scanf("%d %d",&a,&b);
    c=a+b;
    printf("sum is : %d",c);
}