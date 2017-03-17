#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include "conio.h"

using namespace std;
struct node {
	int data;
	struct node *next;
	
};


// 3 things to do:
//1) head -> next should be made NULL
//2) last nodes next should point to previous node.
//3) last node should be made the new head and be returned.
//4) 
struct node * ReverseList(struct node * head) {
	struct node *cur, *prev, *next;
	cur = next = prev= head;
	while (cur != NULL) {
		if (cur == head) {
			next = cur->next;
			cur->next = NULL;
			prev = cur;
		}
		else {
			// how to handle the last node
			//prev = cur;
			next = cur->next;
			cur->next = prev;
			prev = cur;
			}
		
		cur = next;
	}
	return prev;
}

struct node * CreateListNode(int data) {
	struct node * listNode;
	listNode = new node;
	listNode->data = data;
	listNode->next = NULL;
	return listNode;
}

void PrintNode(struct node * head) {
	struct node *tmp = head;
	while (tmp) {
		cout << tmp->data << "\t";
		tmp = tmp->next;
	}
}

//int getCount(struct node *head) {
//	if (!head)
//		return 0;
//	if (!head->next)
//		return 1;
//	int count=0;
//	struct node *slow, *fast;
//	fast =slow = head;
//	while (fast!=NULL && fast->next !=NULL) {
//		fast = fast->next->next;
//		slow = slow->next;
//		++count;
//	}
//
	/*return count;
}*/
//
//void Split(struct node ** head, struct node * a, struct node *b) {
//
//	if (*head = NULL) {
//		a = b = NULL;
//		return;
//	}
//	struct node * tmp;
//	struct node *slow, *fast;
//	fast = slow =  *head;
//	if (fast && fast->next) {
//		while (NULL != fast->next  && NULL != fast->next->next) {
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//	}
//
//	a = *head;
//	if (slow)
//		b = slow->next;
//	else
//		b = NULL;
//	if(slow)
//		slow->next = NULL;
//
//}
//
//struct node * merge(struct node *a, struct node *b) {
//	if(a == NULL)
//		return b;
//	if (b == NULL)
//		return a;
//
//	struct node *result;
//	a->data >= b->data ? result = a,result->next = merge(a->next,b) : result = b, result->next = (a,b->next);
//	return result;
//}
//
//void MergeSortLinkedList(struct node ** headref) {
//	if (!*headref)
//		return;
//	struct node *a,*b;
//	a = b = *headref;
//	Split(headref, a, b);
//	MergeSortLinkedList(&a);
//	MergeSortLinkedList(&b);
//
//	*headref = merge(a, b);
//}

void RecursiveReverseLinkList(struct node *cur, struct node * prev, struct node **start) {
	
	struct node *tmp;
	if (cur == NULL) {
		*start = prev;
		return;
	}
	tmp = cur->next;
	cur->next = prev;
	prev = cur;
	RecursiveReverseLinkList(tmp, prev, start);
}

void FindKNode(struct node *head, int k) {
	if (!head && k <0 )
		return;
	int count = k;
	struct node *tmp = head;
	while (--count) {
		tmp = tmp->next;
	}
	cout << "kth node  " << k << "   number node = " << tmp->data;
}


void FindKNodeFromEnd(struct node *head, int k) {
	if (head && k < 0) {
		cout << "Node not found, enter valid num";
		return;
	}

	struct node *first, *last;
	first = last = head;
	int count = k;
	int mEnd = 1;
	while (count-- && last->next != NULL) {
		++mEnd;
		last = last->next;
		if (count == 0) {
			first = first->next;
			count = k;
		}
	}
	if(mEnd < k) {
		cout << " the number is beyond range \n\n";
		return;
	}
	if (last) {
		cout << "mEnd = " << mEnd << endl;
		cout << "kth item from last = " << k << "  item from last = " << first->data << endl;
	}
	
}

struct node * FindMidOfList(struct node *head) {
	if (!head)
		return NULL;
	struct node * slow, *fast;
	slow = fast = head;
	while (fast->next && fast->next->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	cout << "middle node of the linked list is " << slow->data;

	return slow;
}
bool IsPalindrome(struct node *head) {
	
	bool flag = true;
	if (!head)
		return false;
	struct node *mid;
	mid = FindMidOfList(head);
	struct node *first, *end;
	first = head;
	end = mid;
	int count = 1;
	while (end != NULL) {
		end = end->next;
		++count;
	}
	end = mid;
	struct node *midhead = mid;
	while (first != mid) {
		int k = 1;
		while (k < count) {
			end = end->next;
			++k;
		}
		--count;
		if (!first || !end) {
			flag = false;
			return flag;
		}
			if (first->data != end->data)
				flag = false;
			else {
				first = first->next;
				midhead = midhead->next;
				end = midhead;
			}
	}

	return flag;
}

int main()
{
	struct node *prev, *next, *cur;
	struct node *head = CreateListNode(10);
	head->next = CreateListNode(20);
	head->next->next = CreateListNode(30);
	head->next->next->next = CreateListNode(20);
	head->next->next->next->next = CreateListNode(10);
	//head->next->next->next->next->next = CreateListNode(60);
	cout << "before reversing \n";
	PrintNode(head);
	cout << endl;

	cout << "Find the kth node from beginning\n";
	FindKNode(head, 1);

	cout << "Find K'th node from end \n";
	//FindKNodeFromEnd(head, 5);
	


	FindMidOfList(head);

	if (IsPalindrome(head)){
		cout << " \n\n\n Linked lis is a Palindrome \n\n ";
	}
	else {
		cout << "\n\n\nLinked list is not a palindrome\n\n";
	}
//	cout << "after reversing \n";
	//head = ReverseList(head);
//	RecursiveReverseLinkList(head,NULL,&head);
	//PrintNode(head);
	//MergeSortLinkedList(&head);
	cout << endl;
	//cout << "after sorting \n";
	//PrintNode(head);
	_getch();
	return 0;
}