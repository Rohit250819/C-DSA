#include <stdio.h>
int linearsearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {1, 6, 3, 54, 78, 90, 67, 376, 12, 45, 89};
    int size = sizeof(arr) / sizeof(int);
    int element = 90;
    int searchindex = linearsearch(arr, size, element);
    printf("The element %d is found at index %d\n", element, searchindex);

    return 0;
}