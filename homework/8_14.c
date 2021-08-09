#include <stdio.h>
#include <stdlib.h>

typedef struct Btree{
    int key;
    struct Btree *left, *right;
}Btree;

Btree n1={1,NULL,NULL};
Btree n2={4,&n1,NULL};
Btree n3={16,NULL,NULL};
Btree n4={25,NULL,NULL};
Btree n5={20,&n3,&n4};
Btree n6={15,&n2,&n5};
Btree *root=&n6;
/*
     15
   /    \
  4     20
 /     /  \
1     16  25

*/
int sum(Btree *root){
    if(root ==NULL) return 0;
    return root->key+sum(root->left)+sum(root->right);
}

int main(){
    int k;
    k=sum(root);
    printf("%d",k);

    return 0;
    
}