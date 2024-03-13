#include<stdio.h>

int f(int v){
    int x= 0;
    while(v>0){
        x=x+f(v-1);
    }
    return v;
}

int main(){
    printf("%d",f(3));
    return 0;
}