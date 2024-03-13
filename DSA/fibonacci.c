#include<stdio.h>

void fibbonacci(int n);
void withoutrecursion();

int a=0;
int b=1;


void withoutrecursion(){

    int x;
    int A=0;
    int B=1;

    printf("fibonacci upto n without recursion=\n");
    scanf("%d",&x);
    printf("%d ",A);
    printf("%d ",B);

    for (size_t i = 0; i <=x-2; i++)
    {
        int result=A+B;
        A=B;
        B=result;
        printf("%d ",result);
    }
    
}
void fibbonacci(int n){
    
    if (n==0)
    {
        return ;
    }
    else{

printf("%d \t",a);
int result=a+b;
a=b;
b=result;
fibbonacci(n-1);}
}
void main()
{
    int number;
    printf("press 1.fibbonacci with recursion \n 2.Without recursion:\n");
    scanf("%d ",&number);
    int a;
switch (number)

{
case 1:

printf("fibonacci upto n =");
scanf("%d",&a);

fibbonacci(a);
break;
case 2:
withoutrecursion();
break;
default:
printf("enter valid number ");}
    
}