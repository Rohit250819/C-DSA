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

void InsertInBst(struct Node*root ,int key){
    struct Node*prev=NULL;
    while(root!=NULL){
        prev=root;
        if(key==root->data){
            printf("Can't insert %d , already in BST\n",key);
            return;
        }
        else if(key<root->data){
            root=root->left;

        }
        else{
            root=root->right;
        }

    }
        struct Node *new=CreateNode(key);
        if(key<prev->data){
            prev->left=new;
        }
        else{
            prev->right=new;
        }

    
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

    InsertInBst(j,25);
    printf("%d inserted\n",j->right->left->data);


    return 0;
}