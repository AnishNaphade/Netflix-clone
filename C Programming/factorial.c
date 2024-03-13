#include<stdio.h>

int input;
int factorial(int k);


int main(){
    printf("enter number to calculate factorial:");
    scanf("%d",&input);
    

    int result = factorial(input);
    printf("%d",result);

}

int factorial(int k){
    if(k>=1){
        return k * factorial(k - 1);
    }
    else{
        return 1;
    }
}