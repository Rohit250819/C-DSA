#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int f;
    int r;
    int *arr;
};
int IsFull(struct queue*p){
    if((p->r+1) % p->size==p->f){
        return 1;
    }
    else{
        return 0;
    }
}

void Enqueue(struct queue*p, int val){
      if(IsFull(p)){
          printf("Queue is Full!\n");
      }
      else{
          p->r=(p->r+1)%p->size;
           
          p->arr[p->r]=val;
          printf("Enqueued Element : %d\n",val);
      }
}

int Dequeue(struct queue *p){
    int a=-1;
    if(p->f==p->r){
        printf("Queue is Empty!\n");
    }
    else{
        p->f=(p->f+1)%p->size;
        a=p->arr[p->f];
    }
    return a;
}

int main(){

    struct queue *q;
    q->size=5;
    q->f=q->r=0;
    q->arr=(int*)malloc(q->size*(sizeof(int)));

    Enqueue(q,34);
    Enqueue(q,23);
    Enqueue(q,67);
    Enqueue(q,78);
    Enqueue(q,12);
    printf("\n");
    printf("Dequeue Element : %d\n",Dequeue(q));
    printf("Dequeue Element : %d\n",Dequeue(q));
    printf("Dequeue Element : %d\n",Dequeue(q));
    printf("Dequeue Element : %d\n",Dequeue(q));
    printf("Dequeue Element : %d\n",Dequeue(q));
    


    return 0;
}