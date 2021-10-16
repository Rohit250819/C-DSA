#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
void PrintArray(int *A, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int Maximum(int *A, int len)
{
    int max = INT_MIN;
    for (int i = 0; i < len; i++)
    {
        if (max < A[i])
        {
            max = A[i];
        }
    }
    return max;
}

void CountSort(int *A, int len)
{
    int i, j;
    int max = Maximum(A, len);
    int *count = (int *)malloc((max + 1) * sizeof(int));

    for (i = 0; i <= max; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < len; i++)
    {
        count[A[i]] = count[A[i]] + 1;
    }

    i = 0;
    j = 0;
    while (i <= max)
    {
        if (count[i] > 0)
        {
            A[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{

    int A[] = {23, 45, 67, 89, 4, 9, 10, 36};
    int len = 8;

    PrintArray(A, len);
    CountSort(A, len);
    PrintArray(A, len);

    return 0;
}