#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    int nNumber;
    struct node *link;
}node;

node *head=NULL;
node *tail=NULL;

void init(){
    head->nNumber=0;
    head->link=NULL;
    head->key=0;
}
void insert(int item){
    static int number=1;
    node *temp=(node *)malloc(sizeof(node));
    node *newNode=(node *)malloc(sizeof(node));
    newNode->key=item;
    newNode->link=NULL;
    newNode->nNumber=number;

    //트리 맨 끝에 삽입
    if(tail==NULL){;
        head=newNode;
        tail=newNode;
    }else{  
        tail->link=newNode;
        tail=newNode;
    }

    temp=head;    //비교할 부모노드
    int i=number;
    node*x=(node*)malloc(sizeof(node)); //비교할 자식 노드
    x=tail;

    while(i>1&&temp!=NULL){
        if(temp->nNumber==i/2){ 
            if(temp->key<x->key){
                int k=temp->key;
                temp->key=x->key;
                x->key=k;
                x=temp;
                temp=head;
                i/=2;
            }
            else{
                break;
            }
        }
        else{
            temp=temp->link;
        }
    }
    number++;

}

int main(){
    int item;
    for(int i=0;i<7;i++){
        scanf("%d",&item);
        insert(item);
    }
    printf("최대값: %d",head->key);
}