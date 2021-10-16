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

struct Node *   DeleteAtFirst(struct Node *head)
{
    struct Node*p=head;
    head=head->next;
    struct Node*q=p->next;
    while(q->next!=p){
        q=q->next;
    }

    q->next=p->next;
    // head=p->next;
    // p->next=NULL;
    free(p);
    return q->next;
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
    head = DeleteAtFirst(head);
    
    LinkedListTraversal(head);

    return 0;
}