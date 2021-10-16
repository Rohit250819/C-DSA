#include<stdio.h>
void PrintArray(int*A, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
}

void SelectionSort(int *A,int len){
    int IndexOfMin,temp;
    for (int i = 0; i < len-1; i++)
    {
         IndexOfMin=i;
         for (int j = i+1; j <len; j++)
         {
            if(A[j]<A[IndexOfMin]){
                IndexOfMin=j;
            }
         }
         temp=A[i];
         A[i]=A[IndexOfMin];
         A[IndexOfMin]=temp;

         
    }
    
}

int main(){

    int A[]={45,72,98,27,30,29,67,25,199,628,31,82};
    int len=12;

    PrintArray(A,len);
    SelectionSort(A,len);
    PrintArray(A,len);


    return 0;
}