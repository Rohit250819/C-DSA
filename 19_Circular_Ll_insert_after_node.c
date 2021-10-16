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

struct Node* InsertAfterNode(struct Node*head,struct Node*prevNode,int data){
    struct Node *ptr=(struct Node*)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    return head;
}

int main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    head->data = 2;
    head->next = second;

    second->data = 4;
    second->next = third;

    third->data = 7;
    third->next = NULL;

   printf("Circular Linked List before insertion\n");
    LinkedListTraversal(head);
    head=InsertAfterNode(head,second,47);
    printf("Circular Linked List after insertion\n");
    LinkedListTraversal(head);

    return 0;
}