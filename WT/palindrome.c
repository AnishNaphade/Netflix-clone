#include<stdio.h>

void main(){

    int a;
    printf("enter no:");
    scanf("%d",&a);
int b;

 

for (size_t i = 1; i < a; i++)
{
    if(a%i==0){
        b++;
    }
    
    }

if(b==2){
printf("number is prime");
}

else{
    printf("non prime");
}
}









