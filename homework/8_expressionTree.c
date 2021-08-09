#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    char data;
    struct Node *left, *right;
}Node;

Node n9={4,NULL,NULL};
Node n8={2,NULL,NULL};
Node n7={2,NULL,NULL};
Node n6={4,NULL,NULL};
Node n5={5,NULL,NULL};
Node n4={'*',&n8,&n9};
Node n3={'/',&n6,&n7};
Node n2={'-',&n4,&n5};
Node n1={'+',&n2,&n3};

Node *exp=&n1;

int evaluate(Node *root){
    if(root==NULL)  return 0;
    if(root->left==NULL&&root->right==NULL) return root->data;
    else{
        int op1=evaluate(root->left);
        int op2=evaluate(root->right);
        printf("%d %c %d을 계산합니다.\n",op1,root->data,op2);
        switch(root->data){
            case '+': return op1+op2;
            case '-': return op1-op2;
            case '*': return op1*op2;
            case '/': return op1/op2;
        }
    }
    return 0;
}

int notTerminal(Node* node){
    return(node->left!=NULL || node->right!=NULL);
}

int preorder(Node *root){
    if(root){
        if(notTerminal(root))
            printf("%c",root->data);
        else
            printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int inorder(Node *root){
    if(root){
        inorder(root->left);
        if(notTerminal(root))
            printf("%c",root->data);
        else
            printf("%d",root->data);
        inorder(root->right);
    }
}

int postorder(Node *root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        if(notTerminal(root))
            printf("%c",root->data);
        else
            printf("%d",root->data);
    }
}

int main(){
    printf("수식의 값은 %d 입니다.\n",evaluate(exp));
    printf("전위: ");
    preorder(exp); 
    printf("\n");
    printf("중위: ");
    inorder(exp);
    printf("\n");
    printf("후위: ");
    postorder(exp);
    printf("\n");
    return 0;
}