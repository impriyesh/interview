//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "conio.h"

using namespace std;

struct node {
	int data;
	struct node *left;
	struct node *right;
};

struct node *CreateNode(int data) {
	struct node * tmp = new node;
	tmp->data = data;
	tmp->left = NULL;
	tmp->right = NULL;

	return tmp;
}

void PrintTree(struct node *root)
{
	if (root == NULL)
		return;
	PrintTree(root->left);
	cout << root->data << "\t";
	PrintTree(root->right);
}


void GetPath(struct node *root, vector<int> &path, bool isLeft) {
	if (root == NULL)
		return;

	if (isLeft) {
		// Left Path
		GetPath(root->left, path, isLeft);
		path.push_back(root->data);
	}
	else {
		// Right Path
		path.push_back(root->data);
		GetPath(root->right, path, isLeft);
	}
}

int main()
{
	vector<int> path, left,right;
	struct node * root = CreateNode(50);
	root->left = CreateNode(30);
	root->right = CreateNode(60);
	root->left->left = CreateNode(10);
	root->left->left->right = CreateNode(55);
	root->right->left = CreateNode(40);
	root->right->right = CreateNode(70);
	root->right->right->right = CreateNode(90);
	
	//10   30  50 60 70 90
	PrintTree(root);

	GetPath(root, left, true);
	GetPath(root, right, false);

	path.insert(path.begin(), right.begin(), right.end());
	/*vector<int>::iterator it = right.begin();
	cout << "printing right nodes \n";
	while (it != right.end()) {
		cout << *it;
		++it;
	}*/

	path.insert(path.begin(), left.begin(), left.end()-1);
	cout << endl;
	cout << " Printing smallest node to largest node, from root leftmost along one side to \\
		right node along other side ..." <<endl ;
	for (vector<int>::iterator it = path.begin(); it != path.end(); ++it) {
		cout << *it << " ";
	}
	cout << std::endl;

	_getch();
	return 0;
}