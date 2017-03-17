#include "stdafx.h"
#include <iostream>
//#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#include <vector>
#include <map>

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

void PrintList(vector<struct node*> &nodeList) {

	cout << endl;
	for (int i = 0; i < nodeList.size(); i++)
		cout << nodeList[i]->data << "\t";
}


void FindLongestBstHelper(struct node *root, int min, int max, vector<struct node*> &nodeList, vector<struct node*> &nodeListTmp, int *maxcount, int *count_sofar, bool bstSubtree) {
	if (root == NULL)
		return;
	// now for the false condition,check other nodes down.
	// we need to reset the count of nodes coming from top so far
	if (root->data < min || root->data > max) {
		*count_sofar = 0;
		bstSubtree = !bstSubtree;
		/*if (*tmpMax > *maxcount)
			*maxcount = *tmpMax;
		*tmpMax = 0;*/
		/*if (*count_sofar > * maxcount)
			*maxcount = *count_sofar;*/

		FindLongestBstHelper(root->left, min, root->data - 1, nodeList,nodeListTmp, maxcount, count_sofar,bstSubtree);
		FindLongestBstHelper(root->right, root->data + 1, max, nodeList, nodeListTmp, maxcount, count_sofar,bstSubtree);
	
	}
	else {
		// Set the node address, by geting the max of left and right count
		// of nodes sufficing with the BST property.
		++*count_sofar;
			//*maxcount = *tmpMax;
		/*if (*count_sofar > *tmpMax) {
			*tmpMax = *count_sofar;
			nodeList.push_back(root);
		}
		if (*tmpMax > *maxcount)
			*maxcount = *tmpMax;*/
			if (*count_sofar <= *maxcount && !bstSubtree) {
				nodeListTmp.push_back(root);
			}
			if (*count_sofar > * maxcount) {
 				*maxcount = *count_sofar; 
				nodeList.push_back(root);
			}
			if (!bstSubtree && nodeListTmp.size() >= *maxcount) {
				nodeList.erase(nodeList.begin(),nodeList.begin() + nodeListTmp.size());
				vector<struct node*>::iterator it;
				it = nodeList.begin();
				for (int i = 0; i < nodeListTmp.size(); i++)
					nodeList.insert(it + i, nodeListTmp[i]);
				bstSubtree = !bstSubtree;
				nodeListTmp.clear();
			}

		FindLongestBstHelper(root->left, min, root->data - 1, nodeList, nodeListTmp, maxcount, count_sofar,bstSubtree);
		FindLongestBstHelper(root->right, root->data + 1, max, nodeList, nodeListTmp, maxcount, count_sofar,bstSubtree);
	}
}

void FindLongestBstInBT(struct node *root) {

	vector<struct node *> nodeList;
	vector<struct node *> nodeListTmp;
	int maxCount = 0;
	int countsofar =0;
	bool tmpMax = true;
	

	FindLongestBstHelper(root, INT_MIN, INT_MAX,nodeList, nodeListTmp, &maxCount,&countsofar,tmpMax);
	cout << "\n\n BST in the Btree with highest number of node = " << maxCount << endl;
	PrintList(nodeList);
}

bool isBSTUtil(struct node *root, int min, int max) {

	if (root == NULL)
		return true;

	if (root->data < min || root->data > max)
		return false;
	
	return(isBSTUtil(root->left, min, root->data - 1) && 
		   isBSTUtil(root->right, root->data + 1, max));
}

bool isBST(struct node *root) {

	return(isBSTUtil(root, INT_MIN, INT_MAX));
}

int main(){

	vector<int> path;
	struct node *root = NULL;
	root = CreateNode(4);
	root->left = CreateNode(2);
	root->left->left = CreateNode(1);
	root->left->right = CreateNode(0);
	root->right = CreateNode(5);
	root->right->right = CreateNode(2);
	root->right->right->right = CreateNode(20);
	root->right->right->right->right = CreateNode(21);
	root->right->right->right->right->right = CreateNode(22);
	root->right->right->right->right->right->right = CreateNode(23);
	root->right->right->right->right->right->right->right = CreateNode(24);
	root->right->right->right->right->right->right->right->right = CreateNode(25);

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
	//FindSize(root);

	//FindLongestBstInBT(root);

	if (isBST(root)) {
		cout << endl << " The tree is a BST \n";
	}
	else {
		cout << endl << " The tree is not a BST \n";
	}

	FindLongestBstInBT(root);
	getchar();
 	return 0;

}