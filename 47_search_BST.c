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
struct Node* SearchInBST(struct Node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data<key){
        return SearchInBST(root->right,key);
    }
    else{
        return SearchInBST(root->left,key);
    }
}

struct Node*SearchInBSTITR(struct Node*root, int key){
    while(root!=NULL){
        if(key==root->data){
            return root;
        }
        else if(key<root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return NULL;
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

    struct Node*k=SearchInBST(j,12);
    struct Node*g=SearchInBSTITR(j,25);

    if(k!=NULL){

    printf("Searched Element= %d\n",k->data);
    }
    else{
        printf("Element Not Found!\n");
    }
    if(g!=NULL){

    printf("Searched Element= %d\n",g->data);
    }
    else{
        printf("Element Not Found!\n");
    }


    return 0;
}