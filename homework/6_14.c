#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[12];
    int age;
    double height;
}element;

typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode *link;
} ListNode;


ListNode* insert(ListNode * head,element person){
    ListNode *p=(ListNode *)malloc(sizeof(ListNode));
    strcpy(p->data.name,person.name);
    p->data.age = person.age;
    p->data.height = person.height;

	p->link = head;
	head = p;
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p=head;p!=NULL;p=p->link){
        printf("%4s %4d %4f \n",p->data.name,p->data.age,p->data.height);
    }
    printf("NULL");
        
}

int main(){

    ListNode * head=NULL;
    element person[4]={
        {"Kim",34,1.7},
        {"Park",27,1.2},
        {"Lee",48,1.4},
        {"Choi",30,1.3}
    };

    for(int i=0;i<4;i++){
        head=insert(head,person[i]);
    }
    print_list(head);
}