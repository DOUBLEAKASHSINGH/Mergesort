#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>
void merge(int *A, int p, int q, int r)
{
    int i, j, k, *L, *R;
    int size1 = q - p + 1;
    int size2 = r - q;
    L = (int *)malloc((size1 + 1) * sizeof(int));
    R = (int *)malloc((size2 + 1) * sizeof(int));

    for (i = 0; i < size1; i++)
    {
        L[i] = A[p + i];
    }
    for (j = 0; j < size2; j++)
    {
        R[j] = A[q + j + 1];
    }
    L[i] = INT_MAX;
    R[j] = INT_MAX;
    i = 0;
    j = 0;
    for (k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
}

void mergeSort(int *A, int p, int r)
{
    int q;
    if (p < r)
    {
        q = (p + r) / 2;
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);
        merge(A, p, q, r);
    }
}

void display(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
}

int main()
{
    int *A, n, i;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    printf("please enter the element of Array\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    mergeSort(A, 0, n - 1);
    display(A, n);
    return 0;
}