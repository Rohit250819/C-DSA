#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *left;
    struct Node*right;
};

struct Node* CreateNode(int data){
    struct Node*P=(struct Node*)malloc(sizeof(struct Node));
    P->data=data;
    P->left=NULL;
    P->right=NULL;
    return P;

}
void Postorder(struct Node*root){
    if(root!=NULL){
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ",root->data);
    }
    
}

int main(){

    struct Node*j=CreateNode(4);
    struct Node*j1=CreateNode(1);
    struct Node*j2=CreateNode(6);
    struct Node*j3=CreateNode(5);
    struct Node*j4=CreateNode(2);

    j->left=j1;
    j->right=j2;
    j1->left=j3;
    j1->right=j4;

    Postorder(j);
    printf("->Post Order");


    return 0;
}