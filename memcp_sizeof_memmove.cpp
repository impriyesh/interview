#include "stdafx.h"
#include <iostream>
//#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#include <vector>

struct node {
	int data;
	struct node *left,*right;
};

struct node * CreateNode( int data) {
	
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}


void PrintBtree(struct node * root) {
	if (!root)
		return;
	PrintBtree(root->left);
	cout << root->data << "\t";
	PrintBtree(root->right);
}

void FindSize(struct node *root) {

	// implementing sizeof for finding the size of a struct
	if (!root)
		return;
	else {
		cout << "\n\n Size of struct with 1 int and 2 pointers is  " << sizeof(struct node) <<endl;
		char *a,*b;
		a = (char*)root;
		b = (char*)(root + 1);
		cout << "\n size of struct is  " << b -a  << endl;
	}
}

void MyMemCp(void *dst, void *src, int size) {

	char *csrc = (char*) src;
	char *cdst = (char*) dst;
	for (int i = 0; i < size ; i++) {
		cdst[i] = csrc[i];
	}

}

int main(){

	vector<int> path;
	struct node *root;
	root = CreateNode(4);
	root->left = CreateNode(2);
	root->left->left = CreateNode(1);
	root->left->right = CreateNode(3);
	root->right = CreateNode(5);
	//root->right->right = CreateNode(1);
	//root->right->right->left = CreateNode(1);
	//root->right->right->right = CreateNode(1);
	//root->right->right->right->right = CreateNode(1);
	//root->right->right->right->right->right = CreateNode(1);
	//root->right->right->right->right->right->right = CreateNode(1);
	////root->left->left->left = CreateNode(1);
	//root->left->left->left->left = CreateNode(1);
	//root->left->left->left->left->left = CreateNode(1);
	//root->left->right->right = CreateNode(3);
	//root->left->right->right->right = CreateNode(3);
	//root->left->right->right->right->right = CreateNode(3);
	//root->left->right->right->right->right->right = CreateNode(3);
	//root->left->right->right->right->right->right->right = CreateNode(3);
	//root->left->right->right->right->right->right->right->right = CreateNode(3);
	//root->left->right->right->right->right->right->right->right->right = CreateNode(3);

	PrintBtree(root);
	FindSize(root);

	char csrc[] = "GeeksForGeeks";
	char cdest[1000];

	MyMemCp(cdest, csrc, sizeof(csrc));
	cout << "after MyMemCp  " << cdest;

	int isrc[] = { 10,20,30,40,50 };
	const int n = sizeof(isrc) / sizeof(isrc[0]);
	//const int n = a;
	int idest[n], i;
	MyMemCp(idest, isrc, sizeof(isrc));
	cout << endl; 
	cout << "Memcopy for all the array elements is \n\n";
	for (i = 0; i <n; i++)
		cout << idest[i] << " \t ";



	cout << "\n\nChecking memcpy and memmove \n\n";

	char csrc1[100] = "Geeksfor";
	memcpy(csrc1 + 5, csrc1, strlen(csrc1)+1);
	cout << csrc1;

	cout << endl;
	cout << endl;

	memmove(csrc1+5, csrc1, strlen(csrc1) + 1);
	cout << csrc1;

	getchar();
 	return 0;

}