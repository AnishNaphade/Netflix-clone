#include<stdio.h>

int main() {
    int n1 = 10;
    int n2 = 20;
    int n3 = 30;

    if (n1 > n2) {
        if (n1 > n3) {
            printf("%d is the max number\n", n1);
        } else {
            printf("%d is the greatest no.\n", n3);
        }
    } else if (n2 > n1) {
        if (n2 > n3) {
            printf("%d is the largest no.\n", n2);
        } else {
            printf("%d is the greatest no.\n", n3);
        }
    }

    return 0;
}
