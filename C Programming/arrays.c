#include<stdio.h>

int array1[4];

int main(){
for (size_t i = 0; i < 4; i++)
{
    printf("enter values:\n");
    scanf("%d",&array1[i]);
}

for (size_t i = 0; i < 4; i++)
{
    
    printf("%d",array1[i]);
    
}

return 0;
}
