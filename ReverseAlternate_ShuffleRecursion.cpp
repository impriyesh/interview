#include "stdafx.h""
//#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>


using namespace std;
struct LL {
	int data;
	struct LL *next;
};

struct LL * ReverseAlternate(struct LL * head, int k , bool reverse) {

	struct LL * cur = head;
	struct LL * prev = NULL;
	struct LL* next = NULL;
	int count = 0 ;

	if (reverse) {
		while (cur != NULL && count < k) {
			next = cur->next;
			cur->next = prev;
			prev = cur;
			cur = next;
			++count;
		}
		if(head)
			head->next = ReverseAlternate(cur, k, !reverse);
	}
	else {
		prev = cur;
		struct LL *tmp = NULL;
		while (cur != NULL && count < k) {
			tmp = cur;
			cur = cur->next;
			++count;
		}
		if(tmp)
			tmp->next = ReverseAlternate(cur, k, !reverse);
	}
	return prev;
}

void PrintList(struct LL *head) {
	struct LL *tmp = head;
		while ( tmp != NULL) {
			cout<< tmp->data << "\t";
			tmp = tmp->next;
		}
}

struct LL* InsertNode(struct LL *head, int data) {
 
	struct LL *newNode = (struct LL*)malloc(sizeof(struct LL));
	newNode->data = data;
	newNode->next = NULL;

	if (!head) {
		return newNode;
	}
	struct LL *tmp = head;
	
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = newNode;
	return head;
}

int main() {
	
	struct LL * head = NULL;
	head = InsertNode(head,1);
	head = InsertNode(head, 2);
	head = InsertNode(head, 3);
	head = InsertNode(head, 4);
	head = InsertNode(head, 5);
	head = InsertNode(head, 6);
	head = InsertNode(head, 7);
	head = InsertNode(head, 8);
	head = InsertNode(head, 9);

	cout << "before reversing \n";
	PrintList(head);
	cout << "\n\n\n\After reversing \n";
	head= ReverseAlternate(head, 3, true);
	PrintList(head);
	getchar();

	return 0;
}