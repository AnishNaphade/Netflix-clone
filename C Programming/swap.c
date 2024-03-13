#include<stdio.h>

void swap(int* x , int* y);


int main(){

int x=7; int y=9;

printf("The value of x and y before swapping is:%d %d\n",x,y);


swap(&x,&y);

printf("The value of x and y after swapping is:%d %d",x,y);

return 0;

}


void swap(int* x , int* y){

    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

