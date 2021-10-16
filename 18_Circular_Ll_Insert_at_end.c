#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void LinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *InsertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;

    struct Node *p = head;
    p->next=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;


    return head;
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
    fourth->next = head;

    printf("Circular Linked List Before insertion at End\n");
    LinkedListTraversal(head);
    printf("Circular Linked List After insertion at End\n");
    InsertAtEnd(head, 50);
    
    LinkedListTraversal(head);

    return 0;
}