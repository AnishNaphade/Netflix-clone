#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.
int sum = 0;
int marks_summation(int* marks, int number_of_students, char gender) {
  
  
  
  
  if (gender = 'g')

  {
    if (number_of_students%2==0)
    {
      for (size_t i = 1; i <= number_of_students; i=i+2)
  {
    sum = sum + *(marks + i);
    
  }
    }
  else
  {
    for (size_t i = 1; i <= number_of_students; i=i+2)
  {
    sum = sum + *(marks + i);
    
  }
  }
  }





  else if(gender ='b')
  {
    if (number_of_students%2==0)
    {
      for (size_t i = 0; i <= number_of_students; i=i+2)
  {
    sum = sum + *(marks + i);
    
  }

  }

  else
  {
    for (size_t i = 0; i <= number_of_students-1; i=i+2)
  {
    sum = sum + *(marks + i);
    
  }
    
  }
    
}
}



int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);

    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}



  
  