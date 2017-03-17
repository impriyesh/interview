#include "stdafx.h"
#include <iostream>
//#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node * CreateLinkedList(struct node *head, int data)
{
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = data;
	newNode->next = NULL;
	if (!head) {
		return newNode;
	}
	struct node *tmp, *prev;
	tmp = prev = head;
	while (tmp != NULL) {
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = newNode;
	
	return head;
}

void PrintList(struct node * head) {
	struct node *tmp = head;
	if (!tmp) {
		return;
	}
	while (tmp) {
		cout << tmp->data <<"\t";
		tmp = tmp->next;
	}
}

struct node * ReverseList(struct node *head, int k, bool reverse) {

	//cout << reverse <<endl;
	struct node *curr = head;
	struct node *next = NULL;
	struct node *prev = NULL;

	if (reverse) {
		int count = 0;
		while (curr != NULL && count < k) {
			next = curr->next;
			curr->next = prev;
			prev = curr;;
			curr = next;
			++count;
		}
		if (next != NULL) {
			head->next = ReverseList(next, k, !reverse);
		}
		return prev;
	}
	else {
		int count = 0;
		struct node* temp = curr;
		while (curr != NULL && count < k)
			prev = curr, curr = curr->next, count++;
		if (curr != NULL) {
			prev->next = ReverseList(curr, k, !reverse);
		}

		return temp;
	}
	//while(cur)

}

int main() {
	struct node * head = NULL;
	head=CreateLinkedList(head, 1);
	head=CreateLinkedList(head, 2);
	head=CreateLinkedList(head, 3);
	head=CreateLinkedList(head, 4);
	head=CreateLinkedList(head, 5);
	head=CreateLinkedList(head, 6);
	head=CreateLinkedList(head, 7);
	head=CreateLinkedList(head, 8);

	cout << "reverse the linked list , alternately and in size of k both \n\n \n";

	PrintList(head);
	struct node *root = ReverseList(head, 3, true);

	cout << endl << "reverse the linked list \n\n";
	PrintList(root);
	getchar();
	return 0;

}