#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int*arr;
};

int IsEmpty(struct queue*p){
    if(p->r==p->f){
        return 1;
    }
    else{
        return 0;
    }
}

int IsFull(struct queue*p){
    if(p->r==p->size-1){
        return 1;
    }
    else{
        return 0;
    }

}
void EnqueueR(struct queue*p, int val){
   if(
   IsFull(p)
       
   ){
       printf("Queue is full\n");
   }
   else{
       p->r++;
       p->arr[p->r]=val;
       printf("Enqueued element: %d\n",val);
   } 
}
void EnqueueF(struct queue*p,int val){
    if(IsFull(p)){
        printf("Queue is full\n");
    }
    else{
        if(p->f==-1){
            printf("Can't be put from front!\n");
        }
        else{
            p->arr[p->f]=val;
            p->f--;
            printf("EnqueuedF Element: %d\n",val);

        }
    }
}

int DequeueR(struct queue*p){
    int a=-1;
    if(IsEmpty(p)){
        printf("Queue is Empty\n");
    }
    else{
        a=p->arr[p->r];
        p->r--;
    }
    return a;
}

int DequeueF(struct queue *p){
    int a=-1;
    if(IsEmpty(p)){
        printf("Queue is Empty\n");
    }
    else{
        p->f++;
         a=p->arr[p->f];
    }
    return a ;
}
int main(){

    struct queue *q;
    q->size=8;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

     EnqueueR(q,45);
     EnqueueR(q,67);
     EnqueueR(q,73);
     EnqueueR(q,36);
     printf("DequeuedF Element: %d\n",DequeueF(q));
     printf("DequeuedF Element: %d\n",DequeueF(q));
     EnqueueF(q,89); 
     EnqueueF(q,34);
     EnqueueF(q,98);

     printf("\n");
    
    printf("DequeuedF Element: %d\n",DequeueF(q));
    printf("DequeuedR Element: %d\n",DequeueR(q));

    return 0;
}