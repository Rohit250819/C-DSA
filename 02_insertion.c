#include<stdio.h>
void display(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int indinsertion(int arr[],int size,int element, int capacity, int index){
    if(size>=capacity){
        printf("Insertion unsucessfull!\n");
        return -1;
    }
    for (int i = size-1; i >= index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    printf("Insertion sucessful\n");
    return 1;
}
int main(){

    int arr[50]={1,4,7,23,45};
    int size=5,element=78,index=2;
    display(arr,size);
    indinsertion(arr,size,element,50,index);
    size+=1;
    display(arr,size);
    


    return 0;
}