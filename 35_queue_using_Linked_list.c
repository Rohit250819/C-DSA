#include<stdio.h>
#include<stdlib.h>

struct Node*f=NULL;
struct Node*r=NULL;

struct Node{
    int data;
    struct Node*next;
};

void LinkedListTraversal(struct Node *ptr)
{
    printf("Linked List\n");
    while (ptr!= NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


void Enqueue(int data){
          struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
          if(ptr==NULL ){
              printf("Queue is Full!\n");
          }
          else if(f==NULL){
              ptr->data=data;
              f=r=ptr;
              printf("Enqueued Element: %d\n",ptr->data);
          }
          else{
             r->next=ptr;
             ptr->data=data;
             r=ptr;
             ptr->next=NULL;
             printf("Enqueued Element: %d\n",ptr->data);
          }
}

int Dequeue(){
    int a=-1;
    struct Node*p=f;
     
    if(f==NULL){
        printf("Queue is Empty!\n");
    }
    else{
        f=f->next;
        a=p->data;
        free(p);
    }
    return a;
}

int main(){
       LinkedListTraversal(f);

       Enqueue(10);
       Enqueue(30);
       Enqueue(27);
       Enqueue(67);
       printf("Dequeued Element: %d\n",Dequeue());
       printf("Dequeued Element: %d\n",Dequeue());
        printf("\n");

       LinkedListTraversal(f);
    


    return 0;
}