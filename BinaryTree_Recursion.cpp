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

int FindDepth(struct node *root) {
	int left, right;
	if (!root)
		return 0;
	else {
		left  = FindDepth(root->left);
		right = FindDepth(root->right);
		if (left > right)
			return (1 + left);
		else
			return (1 + right);
	}
	
}

int CountNodesInBinarytree(struct node * root) {
	if (!root)
		return 0;
	int left,right;
	left = CountNodesInBinarytree(root->left);
	right = CountNodesInBinarytree(root->right);
	return (1 + left + right);

}


bool isSumInPath(struct node *node, int num) {
	bool flag = false;
	if (!node)
		return false;
	else {
		if (num - node->data == 0 && !(node->left) && !(node->right) ) {
			flag = true;
			return flag;
		}
		else {
			flag = isSumInPath(node->left, num-node->data);
			if (flag )
				return flag;
			else {
				flag = isSumInPath(node->right, num - node->data);
			}
		}
	}
}

void PrintArray(vector<int> &path) {
	
	for (int i = 0; i < path.size();i++) {
		cout<<path[i];
	}
	cout << endl;
}
void PrintPathsRecur(struct node *node, vector<int> &path) {
	if (node == NULL)
		return;
	// append this node to the path array
	path.push_back(node->data);

	// if its a leaf node, so print the path that leads to here
	if (node->left == NULL && node->right == NULL){
		PrintArray(path);
		//path.pop_back();
	}
	else {
		//otherwise try both subtrees
		PrintPathsRecur(node->left, path);
		PrintPathsRecur(node->right, path);
	}
	path.pop_back();

}

void PrintPaths(struct node *node) {
	vector<int> path;
	PrintPathsRecur(node, path);
}

void mirror(struct node *node) {
	if (node == NULL)
		return;
	
	mirror(node->left);
	mirror(node->right);

	struct node *tmp;
	tmp = node->left;
	node->left = node->right;
	node->right = tmp;

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

	cout << "Depth of tree =  " << FindDepth(root) << endl << endl;
	cout << "Path of the longest rood to leaf node is  "; 
	PrintPaths(root);
	PrintBtree(root);
	cout << endl;
	cout << "Number of nodes in the tree = " << CountNodesInBinarytree(root);
	int num = 22;
	if (isSumInPath(root, num)) {
		cout << "\n\n Ohh yes sum of path having sum =" << num << " is present in the path ";
	}
	else {
		cout << " \n\n Ohh No sum of path having sum =" << num << " is not present in the path ";
	}

	cout << " \n\n\n Printing paths from root to leaf for all path \n\n\n";
	PrintPaths(root);
	cout << endl;

	cout << "Mirror view of the tree \n\n ";
	mirror(root);
	PrintBtree(root);
	getchar();
 	return 0;

}