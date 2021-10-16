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
void Enqueue(struct queue*p, int val){
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

int Dequeue(struct queue *p){
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
    q->size=4;
    q->f=q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    Enqueue(q,12);
    Enqueue(q,16);
    Enqueue(q,18);
    Enqueue(q,34);

    printf("\n");
     printf("Dequeued Element: %d\n",Dequeue(q));
     printf("Dequeued Element: %d\n",Dequeue(q));
     printf("Dequeued Element: %d\n",Dequeue(q));
     printf("Dequeued Element: %d\n",Dequeue(q));
     printf("Dequeued Element: %d\n",Dequeue(q));


    return 0;
}