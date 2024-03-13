#include<stdio.h>


int maxoffour(int a,int b,int c,int d);


int  main()
{
int a,b,c,d,g;


    printf("enter integer:");
    scanf("%d",&a);
    

    printf("enter integer:");
    scanf("%d",&b);
  

    printf("enter integer:");
    scanf("%d",&c);
    

    printf("enter integer:");
    scanf("%d",&d);

    

    g = maxoffour(a,b,c,d);

    printf("greatest integer is:%d",g);

    return 0;
}




int maxoffour(int a,int b,int c,int d){

int max;
max = a;

if(b>max){
    max = b;
}

if(c>max){
    max = c;
}

if(d>max){
    max = d;
}

return max;

}



