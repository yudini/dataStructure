#include<stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode *link;
} ListNode;

ListNode* insert(ListNode *head, int value)
{
    ListNode * point;
    ListNode *p = (ListNode *)malloc(sizeof(ListNode)); 
    p->data = value;
    p->link = NULL;
    if(head==NULL)    //데이터가 하나도 없을 때
        head = p;
    else if(head->link==NULL){  //데이터가 하나만 있을 때
        if(head->data<=p->data)   //끝에 삽입
           head->link =p;
        else{   //앞에 삽입
            p->link=head;
            head=p;
        }
    }
    else{   //데이터가 두개 이상일 때
        point=head;
        while(point){
            if(point == head && point->data>=p->data){
                p->link =head;   //맨 앞에 삽입
                head=p;
                break;
            }else if(point->link ==NULL && point->data<p->data){
                point->link=p;    //맨 끝에 삽입
                break;
            }else if(point->data<p->data&&point->link->data>=p->data){
                p->link=point ->link;  //가운데 삽입
                point->link =p;
                break;
            }else
                point=point ->link;   //삽입할 위치 찾아 다음 포인터로
        }
    }
    return head;
}
ListNode* delete(ListNode *head)
{
  ListNode *removed;
  if (head == NULL) return NULL;
  removed = head;	       
  head = removed->link; 
  free(removed);	      
  return head;
}
void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d ", p->data);
}

int main(void)
{
	ListNode *head = NULL;
    int num;
    while(1){
        scanf("%d",&num);
        if(num==-99)
            break;
        head=insert(head,num);
    }
    print_list(head);
	return 0;
}
