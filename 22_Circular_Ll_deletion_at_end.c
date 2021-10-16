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

struct Node *   DeleteAtEnd(struct Node *head)
{
    struct Node*p=head;
     
    struct Node*q=head->next;
    while(q->next!=head){
        q=q->next;
        p=p->next;
    }

    p->next=head;
     
    free(q);
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

    printf("Circular Linked List Before Deletion at first\n");
    LinkedListTraversal(head);
    printf("Circular Linked List After Deletion at first\n");
    head = DeleteAtEnd(head);
    
    LinkedListTraversal(head);

    return 0;
}