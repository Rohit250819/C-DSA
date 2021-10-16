#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *DeletionAtGivenValue(struct Node*head,int value){
    struct Node*ptr=head;
    struct Node*q=head->next;
    while(q->data!=value && q->next!=NULL){
        ptr=ptr->next;
        q=q->next;
    }
    if(q->data==value){
    ptr->next=q->next;
    free(q);
    printf("\nLinked List After Deletion\n\n");
    return head;

    }
    else{printf("Element Not Found!!\n");}

}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 7;
    third->next = fourth;

    fourth->data = 10;
    fourth->next = NULL;

    printf("Linked List Before deletion\n");
    LinkedListTraversal(head);
    head=DeletionAtGivenValue(head,7);
    // printf("Linked List after deletion\n");
    LinkedListTraversal(head);


    return 0;
}