#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode *link;
} ListNode;

ListNode* insert(ListNode *head, int value)
{
      ListNode *p 
           = (ListNode *)malloc(sizeof(ListNode)); //(1)
      p->data = value;	// (2)
      p->link = head;	// (3)
      head = p;	// (4)
      return head;
}

ListNode* delete(ListNode *head)
{
  ListNode *removed;
  if (head == NULL) return NULL;
  removed = head;	       // (1)
  head = removed->link; // (2)
  free(removed);	      // (3)
  return head;
}
void print_list(ListNode *head)
{
	for (ListNode *p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int searchMax(ListNode *head)
{
	ListNode *p =head;
    int max=0;
	
	while(p!=NULL){
		if(p->data>max)
           max=p->data;
		p=p->link;
	}
    return max;
}

int searchMin(ListNode *head){
    ListNode *p =head;
    int min=9999;
	
	while(p!=NULL){
        if(p->data<min)
           min=p->data;
		p=p->link;
	}
    return min;
}

int main(){
    ListNode *head = NULL;

    int array[5]={23,10,39,58,9};

	for (int i = 0; i < 5; i++) {
		head = insert(head, array[i]);
		print_list(head);
	}

    printf("최대값: %d 최소값: %d ",searchMax(head),searchMin(head));
	return 0;
}