#include<stdio.h>
void PrintArray(int*A, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
}

void InsertionSort(int *A, int len){
    int key,j;
    for (int i = 1; i < len; i++)
    {
        key=A[i];
        j=i-1;
        while(j>-1 && A[j]>key){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
    
}

int main(){

    int A[]={3,56,78,37,7,9,87};
    int n=7;
    PrintArray(A,n);
    InsertionSort(A,n);
    PrintArray(A,n);



    return 0;
}