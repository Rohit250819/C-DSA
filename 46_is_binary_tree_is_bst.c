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
void Inorder(struct Node*root){
    if(root!=NULL){
        Inorder(root->left);
        printf("%d ",root->data);
        Inorder(root->right);
    }
}
int IsBST(struct Node*root){
    static struct Node*prev=NULL;
    if(root!=NULL){
        if(!IsBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return IsBST(root->right);
    }
    else{
        return 1;
    }
}

int main(){

    struct Node*j=CreateNode(5);
    struct Node*j1=CreateNode(3);
    struct Node*j2=CreateNode(6);
    struct Node*j3=CreateNode(-2);
    struct Node*j4=CreateNode(4);

    j->left=j1;
    j->right=j2;
    j1->left=j3;
    j1->right=j4;

    Inorder(j);
    printf("->In Order\n");

    if(IsBST(j)){
        printf("This is a BST\n");
    }
    else{
        printf("This is not a BST\n");
    }


    return 0;
}