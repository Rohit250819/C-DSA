#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void Push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stackoverflow! can't be pushed further values in Stack\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
int POp(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stackunderflow! can't pop value from stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
int Peek(struct stack *ptr, int i)
{
    int arrayInd = ptr->top + 1 - i;
    if (arrayInd < 0)
    {
        printf("Not a valid position in stack!\n");
        return -1;
    }
    else
    {
        return ptr->arr[arrayInd];
    }
}

int StackTop(struct stack *ptr)
{
    return ptr->arr[ptr->top];
}

int StackBottom(struct stack *ptr)
{
    return ptr->arr[0];
}

int main()
{

    struct stack *p = (struct stack *)malloc(sizeof(struct stack));
    p->size = 20;
    p->top = -1;
    p->arr = (int *)malloc(p->size * sizeof(int));
    printf("Stack has been created successfully!\n\n");
    // if(isEmpty){
    //     printf("Stack is empty\n");
    // }
    // else{
    //     printf("Stack is not empty\n");
    // }
    printf("Before pushing, Full: %d\n", isFull(p));
    printf("Before pushing, Empty: %d\n", isEmpty(p));
    // pushing values in stack
    Push(p, 3);
    Push(p, 56);
    Push(p, 8);
    Push(p, 2);
    Push(p, 9);
    Push(p, 98);
    Push(p, 28);
    Push(p, 82);
    printf("\n");
    printf("After pushing, Full: %d\n", isFull(p));
    printf("After pushing, Empty: %d\n", isEmpty(p));
    printf("\n");

    // poppong values from stack

    printf("popped %d from the stack\n", POp(p));
    printf("popped %d from the stack\n", POp(p));
    printf("popped %d from the stack\n", POp(p));
    printf("popped %d from the stack\n", POp(p));
    printf("\n");

    // printing remaining values in stack
    for (int i = 1; i <= p->top + 1; i++)
    {
        printf("The value at the position %d is %d\n", i, Peek(p, i));
    }

    printf("\n");
    // printing stack top and bottom values
    printf("Top of the stack: %d\n", StackTop(p));
    printf("Bottom of the stack: %d\n", StackBottom(p));

    return 0;
}