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
struct Node *DeletionAtFirst(struct Node *head )
{
     struct Node *ptr ;
     ptr=head;
     head=head->next;
     free(ptr);
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

    printf("Linked List before Deletion\n");
    LinkedListTraversal(head);
    head=DeletionAtFirst(head);
    // head=DeletionAtFirst(head);
    printf("\nLinked List after Deletion\n");
    LinkedListTraversal(head);

    return 0;
}