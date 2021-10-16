#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
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
void Push(struct stack *ptr, char val)
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
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int ParenthesisMatching(char *exp)
{
    struct stack *p;
    p->size = 30;
    p->top = -1;
    p->arr = (char *)malloc(p->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            if (!isFull(p))
            {

                Push(p, '(');
            }
        }
        else if (exp[i] == ')')
        {
            if (p->arr[p->top] == '(' && !isEmpty(p))
            {
                POp(p);
            }
            else
            {
                return 0;
                break;
            }
        }
        if (exp[i] == '{')
        {
            if (!isFull(p))
            {

                Push(p, '{');
            }
        }
        else if (exp[i] == '}')
        {
            if (p->arr[p->top] == '{' && !isEmpty(p))
            {
                POp(p);
            }
            else
            {
                return 0;
                break;
            }
        }
        if (exp[i] == '[')
        {
            if (!isFull(p))
            {

                Push(p, '[');
            }
        }
        else if (exp[i] == ']')
        {
            if (p->arr[p->top] == '[' && !isEmpty(p))
            {
                POp(p);
            }
            else
            {
                return 0;
                break;
            }
        }
    }
    if (isEmpty(p))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    char *exp = "[{()]}";

    if (ParenthesisMatching(exp))
    {
        printf("Parenthesis Balanced\n");
    }
    else
    {
        printf("Parenthesis Unbalanced\n");
    }

    return 0;
}