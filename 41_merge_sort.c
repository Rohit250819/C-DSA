#include <stdio.h>

void PrintArray(int *A, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Merge(int *A, int mid, int low, int high)
{
    int i, j, k, b[50];
    i = low;
    j = mid+1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            b[k] = A[i];
            i++;
            k++;
        }
        else
        {
            b[k] = A[j];
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        b[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        b[k] = A[j];
        j++;
        k++;
    }

    for (int m = low; m <= high; m++)
    {
        A[m] = b[m];
    }
}
void MergeSort(int *A, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, mid, low, high);
    }
}
int main()
{

    int A[] = {2, 6, 9, 10, 46, 87, 93, 28, 58,8};
    int len = 10;

    PrintArray(A, len);
    MergeSort(A, 0, len - 1);
    PrintArray(A, len);

    return 0;
}