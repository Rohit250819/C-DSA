#include<stdio.h>

void PrintArray(int*A, int len){
    for (int i = 0; i < len; i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    
}

void BubbleSortAdaptive(int *A,int len){
    int temp;
    for (int i = 0; i < len-1; i++)
    {
        printf("Working on pass number: %d\n",i+1);
        int issorted=1;
        for (int j = 0; j < len-1-i; j++)
        {
           if(A[j]>A[j+1]){
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
               issorted=0;
           }
           
        }
        if(issorted){
            return;
        }
        
    }
    
}

int main(){

    int A[]={3,5,6,78,92,45,72,88};
    // int A[]={1,2,5,6,8,9,10,18,38,90,35,72,86,100,700};
    int n=8;
    PrintArray(A,n);
    BubbleSortAdaptive(A,n);
    PrintArray(A,n);


    return 0;
}