#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }


    /*  

   for(i = num - 1; i < 0; i--) {
        printf("%d", *(arr - i));
    }
*/

for(i = num - 1; i<=0 ; i--) {
    for ( int j = 0; j <= num ; j++)
    {
        printf("%d", *(arr - j));
    }
    }
    
        
    

    


return 0;

}