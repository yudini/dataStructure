#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode {
	int data;
	struct ListNode* link;
} Lnode;
void print(Lnode* head) {
	while (head != NULL) {
		printf("%3d ", head->data);
		head = head->link;
	}
	printf("\n");
}
Lnode* insert_first(Lnode* head, int val) {
	Lnode* p = (Lnode*)malloc(sizeof(Lnode));
	if (p == NULL) return;
	p->data = val;
	p->link = head;
	head = p;
	return head;
}

void delete(Lnode* head, int val) {
	Lnode* p = head;
	Lnode* q;
	if (p == NULL) return;
	if (p->data == val) head = p->link;
	else 
		do {
			q = p;
			p = p->link;
			if (p->data == val) {
				q->link = p->link;
				free(p);
				break;
			}
		} while (p != NULL);
}
/*
Lnode* delete(Lnode* head, int val) {
	Lnode* p = head;
	Lnode* q;
	if (p == NULL) return;
	if (p->data == val) head = p->link;
	else
		do {
			q = p;
			p = p->link;
			if (p->data == val) {
				q->link = p->link;
				free(p);
				break;
			}
		} while (p != NULL);
		return head;
}

void delete2(Lnode** head, int val) {
	Lnode* p = *head;
	Lnode* q;
	if (p == NULL) return;
	if (p->data == val) *head = p->link;
	else
		do {
			q = p;
			p = p->link;
			if (p->data == val) {
				q->link = p->link;
				free(p);
				break;
			}
		} while (p != NULL);
} */
void main(void) {
	Lnode* list = NULL;
	int val = 0;
	for (int i = 30; i <= 70; i += 10) {
		list = insert_first(list, i);
		print(list);
	}
	delete(list, 50); print(list);
	delete(list, 30); print(list);
	delete(list, 70); print(list); // ???
}