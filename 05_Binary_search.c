#include<stdio.h>
int binarysearch(int arr[],int size,int element){
    int low, mid, high;
    low=0;
    high=size-1;
    while(low<=high){
      mid=(low+high)/2;
      if(arr[mid]==element){
          return mid;
      }
      if(arr[mid]<element){
          low =mid+1;
      }
      else{
          high=mid-1;
      }
    }
    return -1;
    
}

int main(){

    int arr[]={1,3,4,6,7,56,74,90,124,789,900};
    int size=sizeof(arr)/sizeof(int);
    int element=90;
    int indexsearch=binarysearch(arr,size,element);
    printf("The element %d is present at index %d",element,indexsearch);


    return 0;
}