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
struct Node *DeletionAtIndex(struct Node *head, int index)
{
    struct Node *ptr = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        ptr = ptr->next;
        q = q->next;
    }
    ptr->next = q->next;
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
    fourth->next = NULL;

    printf("Linked List Before deletion\n");
    LinkedListTraversal(head);
    head = DeletionAtIndex(head, 2);
    printf("Linked List after deletion\n");
    LinkedListTraversal(head);

    return 0;
}