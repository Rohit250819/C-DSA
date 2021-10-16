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

struct Node *   DeleteAtIndex(struct Node *head,int index)
{
    struct Node*p=head;
    
    struct Node*q=head->next;
    for (int i = 0; i < index-1; i++)
    {
        p=p->next;
        q=q->next;
    }
    

    p->next=q->next;
    
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
    head = DeleteAtIndex(head,2);
    
    LinkedListTraversal(head);

    return 0;
}