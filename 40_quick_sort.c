#include <stdio.h>

void PrintArray(int *A, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int Partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void QuickSort(int *A, int low, int high)
{
    if (low < high)
    {
        int PartitionIndex = Partition(A, low, high);
        QuickSort(A, low, PartitionIndex - 1);
        QuickSort(A, PartitionIndex + 1, high);
    }
}

int main()
{

    int A[] = {45, 89, 62, 34, 9, 28, 18, 82, 90, 16, 5, 42, 108, 94};
    int len = 14;

    PrintArray(A, len);
    QuickSort(A, 0, len - 1);
    PrintArray(A, len);

    return 0;
}