#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { 	// 노드 타입
	element data;
	struct ListNode *link;
} ListNode;
// 리스트의 항목 출력
void print_list(ListNode* head)
{
	ListNode* p;
	if (head == NULL) return;
	p = head->link;
	do {
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d \n", p->data); // 마지막 노드 출력
}
ListNode* insert_last(ListNode* head, element data)
{
	ListNode *node = (ListNode *)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;	// (1)
		head->link = node;		// (2)
		head = node;		// (3)
	}
	return head;	// 변경된 헤드 포인터를 반환한다. 
}

ListNode *search(ListNode *L, element data)
{
	ListNode *p =L;
	
	while(p!=NULL){
		if(p->data == data) return p;
		p=p->link;
	}
}
// 원형 연결 리스트 테스트 프로그램
int main(void)
{
	ListNode *head = NULL, *node = NULL;

	head = insert_last(head, 20);
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_last(head, 50);
	print_list(head);  // list = 10->20->30->40->50
	node = search(head, 30);
	if (node != NULL) printf("Found\n");
	else		  printf("Not Found\n");
	node = search(head, 50);
	if (node != NULL) printf("Found\n");
	else		  printf("Not Found\n");

    return 0;
}