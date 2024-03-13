#include<stdio.h>
#include <stdlib.h>


int  main()
{
    int* ptr1; 
    

    ptr1=(int*)malloc(6*sizeof(int));

    for (size_t i = 0; i < 6; i++)
    {
        printf("Enter the value of %d element: \n ",i);
        scanf("%d",&ptr1[i]);
        
    }

    for (size_t i = 0; i < 6; i++)
    {
        printf("The value of %d element is:%d \n ",i,ptr1[i]);
    }
    
    
    return 0;
}