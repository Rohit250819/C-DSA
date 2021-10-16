#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node*prev;
    struct Node*next;
};

void DoublyLinkedListTraversal(struct Node*ptr){
    while(ptr!=NULL){
        printf("Element: %d\n",ptr->data);
        ptr=ptr->next;
    }
}


struct Node* InsertAtFirst(struct Node*head,int data){
    struct Node*ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=head;
    return ptr;

}

int main(){

    struct Node*head;
    struct Node*second;
    struct Node*third;
    struct Node*fourth;

    head=(struct Node*)malloc(sizeof(struct Node));
    second=(struct Node*)malloc(sizeof(struct Node));
    third=(struct Node*)malloc(sizeof(struct Node));
    fourth=(struct Node*)malloc(sizeof(struct Node));

    head->data=2;
    head->prev=NULL;
    head->next=second;

    second->data=4;
    second->prev=head;
    second->next=third;

    third->data=7;
    third->prev=second;
    third->next=fourth;

    fourth->data=10;
    fourth->prev=third;
    fourth->next=NULL;

    printf("Doubly Linked List\n");
    printf("Before Insertion\n");
    DoublyLinkedListTraversal(head);

    head=InsertAtFirst(head,1);
    printf("After Insertion\n");
    DoublyLinkedListTraversal(head);



    return 0;
}