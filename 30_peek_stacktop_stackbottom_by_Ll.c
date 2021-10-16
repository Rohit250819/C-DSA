#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node*next;
};

void LinkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element : %d\n",ptr->data);
        ptr=ptr->next;
    }
}
int IsEmpty(struct Node*top){
    if(top==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
int IsFull(struct Node*top){
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Node *Push(struct Node*top,int data){
    if (IsFull(top)){
        printf("Stack Overflow!\n");
    }
    else{
        struct Node*n=(struct Node*)malloc(sizeof(struct Node));
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }
}

int Pop(struct Node**top){
    struct Node*n=*top;
    *top=(*top)->next;
    int x= n->data;
    free(n);
    return x;

}
int Peek(struct Node* top, int Pos){
    struct Node*ptr=top;
    for (int i = 0; i < Pos-1; i++)
    {
        ptr=ptr->next;
    }

    if(ptr!=NULL){
        return ptr->data;
    }
    else{
        return -1;
    }
    

}
int StackTop(struct Node*top){
    return top->data;
}

int StackBottom(struct Node*top){
    struct Node*p=top;
    while((p->next!=NULL)){
        p=p->next;
    }
    return p->data;
}


int main(){

    struct Node*top=NULL;
    int m=4;
     printf("Empty: %d\n",IsEmpty(top));
    top= Push(top,3);
    top= Push(top,46);
    top= Push(top,8);
    top= Push(top,9);
    top= Push(top,92);

    LinkedListTraversal(top);
    printf("Element is at position %d is %d\n",m,Peek(top,m));
    printf("Stack Top: %d\n",StackTop(top));
    printf("Stack Bottom: %d\n",StackBottom(top));


    return 0;
}