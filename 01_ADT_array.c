#include<stdio.h>
#include<stdlib.h>
struct myarray{
    int total_size;
    int used_size;
    int*ptr;
};
void createarray(struct myarray*r,int tsize,int usize){
    r->total_size=tsize;
    r->used_size=usize;
    r->ptr=(int*)malloc(tsize*sizeof(int));
}
void show(struct myarray*r){
    for (int i = 0; i <r->used_size; i++)
    {
        printf("%d\n",(r->ptr)[i]);
    }
    
}
void setval(struct myarray*r){
    int n;
    for (int i = 0; i <r->used_size; i++)
    {
        printf("Enter the value %d:",i);
        scanf("%d",&n);
        (r->ptr)[i]=n;
    }
    
}

int main(){

    struct myarray marks;
    createarray(&marks,10,2);
    printf("We are running setval now\n");
    setval(&marks);
    printf("We are running show now\n");
    show(&marks);


    return 0;
}