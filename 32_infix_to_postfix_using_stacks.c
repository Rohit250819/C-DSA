#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
int Pop(struct stack *ptr)
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

int Stacktop(struct stack*ptr){
    return ptr->arr[ptr->top];
}

int Precedence(char c){
    if(c=='*' || c=='/'){
        return 3;
    }
    else if(c=='+' || c=='-'){
        return 2;
    }
    else {
        return 0;
    }
}

int IsOperator(char c){
    if(c=='+' || c=='-' ||c=='*' ||c=='/'){
        return 1;
    }
    else{
        return 0;
    }
}

char *InfixToPostfix(char * infix){
    struct stack *p=(struct stack*)malloc(sizeof(struct stack));
    p->size=20;
    p->top=-1;
    p->arr=(char*)malloc(p->size*sizeof(char));
    char*postfix=(char*)malloc((strlen(infix)+1)*sizeof(char));
    int i= 0;
    int j= 0;

     
    
    while(infix[i]!='\0'){
        if(!IsOperator(infix[i])){
            postfix[j]=infix[i];
            j++;
            i++;
        }

        else if(Precedence(infix[i])>Precedence(Stacktop(p))){
            Push(p,infix[i]);
            i++;
        }
        else{
            postfix[j]=Pop(p);
            j++;
        }
        
    }

    while(!isEmpty(p)){
        postfix[j]=Pop(p);
        j++;
    }
    postfix[j]='\0';
    return postfix;

}
 

int main(){

    char*infix="h+o-k*h/j/k+h-k";

    printf("Postfix Expression : %s\n",InfixToPostfix(infix));


    return 0;
}