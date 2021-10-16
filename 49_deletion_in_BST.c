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

struct Node*InOrderPredecessor(struct Node*root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct Node* DeletionInBST(struct Node* root, int val){
    struct Node *ipre;

    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(val<root->data){
        root->left=DeletionInBST(root->left,val);
    }
    else if(val>root->data){
        root->right=DeletionInBST(root->right,val);
    }
    else{
        ipre=InOrderPredecessor(root);
        root->data=ipre->data;
        root->left=DeletionInBST(root->left,ipre->data);
    }
    return root;

}

int main(){

    struct Node*j=CreateNode(20);
    struct Node*j1=CreateNode(15);
    struct Node*j2=CreateNode(25);
    struct Node*j3=CreateNode(12);
    struct Node*j4=CreateNode(17);

    j->left=j1;
    j->right=j2;
    j1->left=j3;
    j1->right=j4;

    Inorder(j);
    printf("\n");
    DeletionInBST(j,12);
    Inorder(j);


    return 0;
}