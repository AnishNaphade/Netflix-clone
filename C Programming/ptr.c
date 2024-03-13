#include<stdio.h>

void update(int* a,int* b);




int  main()
{

int a = 5; int b = 7;

update(&a,&b);


return 0;

}




void update(int* a,int* b){

int sum = *a + *b;
int diff;
if(*a > *b){
    diff = *a - *b;
}
else{
    diff = *b - *a;
}

printf("%d\n",sum);
printf("%d",diff);


}