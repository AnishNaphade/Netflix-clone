
// C program to create dynamic array using malloc() function 

#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 

	// address of the block created hold by this pointer 
	int* ptr; 
	int size;
    int sum = 0; 

	// Size of the array 
	printf("Enter size of elements:"); 
	scanf("%d", &size); 

	// Memory allocates dynamically using malloc() 
	ptr = (int*)malloc(size * sizeof(int)); 


for (int j = 0; j < size; j++) { 
			printf("enter elements:");
            scanf("%d",&ptr[j]);
		} 
	

		

		// Print the elements of the array 
		printf("The sum of elements of the array are: "); 
		for (int k = 0; k < size; k++) { 
			sum = sum + ptr[k];

		} 

printf("%d",sum);

        return 0; 
	} 

	

