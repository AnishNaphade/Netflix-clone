#include<stdio.h>

int main(){
    int ages[]={22,11,3,4,5,6,7,};

int length = sizeof(ages) / sizeof(ages[0]);
int highestAge = ages[0];

    for (int i = 0; i < length; i++)
    {
        if(highestAge < ages[i]) {

            highestAge=ages[i];
        }

    }printf("%d", highestAge);
return 0;
    
    
}
