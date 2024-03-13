#include <stdio.h>
void merge(int a[], int lb, int mid, int ub);
void mergesort(int a[], int lb, int ub);

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb;
    int j = mid + 1;
    int k = 0;
    int t = ub - lb + 1;
    int b[t];

    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            k++;
            i++;
        }
        else
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            b[k] = a[j];
            k++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            b[k] = a[i];
            k++;
            i++;
        }
    }
    for (int l = 0; l < t; l++)
    {
        a[lb + l] = b[l];
    }
}
void mergesort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergesort(a, lb, mid);
        mergesort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}
void main()
{
    int a[5] = {};
    
    int n = sizeof(a);
    int m = n / 4;
    printf("enter array of length 5\n");
    for (int i = 0; i <m; i++)
    {
    scanf("%d",&a[i]);
    }
    
    mergesort(a, 0, m - 1);
    for (size_t i = 0; i < m; i++)
    {
        printf("%d \t", a[i]);
    }
}
