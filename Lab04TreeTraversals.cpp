//Lane Snively
//Cosc2030, lab04: binary trees
//due march 11, 2019
#include<iostream>

using namespace std;

struct Node{
	int value;
	struct Node * rightNode = NULL;
	struct Node * leftNode = NULL;
};

Node * searchNode(Node * root, int value){
	Node * rightResult;
	Node * leftResult;
	if(root == NULL){
		return NULL;
	}
	else if (root->value == value){
		return root;
	}
	else{
		rightResult = searchNode(root->rightNode, value);
		leftResult = searchNode(root->leftNode, value);
		if (rightResult == NULL && leftResult == NULL){
			return NULL;
		}
		else if(rightResult != NULL){
			return rightResult;
		}
		else{
			return leftResult;
		}
	}
}

//lane added
void insertLeft(Node * Parent, Node * nodeToInsert) {
	Parent->leftNode = nodeToInsert;
}

//lane added
void insertRight(Node * Parent, Node * nodeToInsert) {
	Parent->rightNode = nodeToInsert;
}


int preOrderTransversal(Node * root){
	if(root != NULL){
		preOrderTransversal(root->leftNode);
		cout << root->value << endl;
		preOrderTransversal(root->rightNode);
	}
	return 0;
}

//lane added
int postOrderTransversal(Node * root) {
	if (root != NULL)
	{
		postOrderTransversal(root->leftNode);
		postOrderTransversal(root->rightNode);
		cout << root->value << endl;
	}
	return 0;
}

//lane added
int inOrderTransversal(Node * root) {
	if (root != NULL)
	{
		cout << root->value << endl;
		inOrderTransversal(root->leftNode);
		inOrderTransversal(root->rightNode);
	}
	return 0;
}

int main(){
	Node * BinaryTree = new Node;
	BinaryTree->value = 5;

	Node * tmp = new Node;
	tmp->value = 4;
	insertLeft(BinaryTree, tmp);

	tmp = new Node;
	tmp->value = 1;
	insertRight(BinaryTree, tmp);

	tmp = new Node;
	tmp->value = 10;
	insertLeft(BinaryTree->leftNode, tmp);

	tmp = new Node;
	tmp->value = 15;
	insertRight(BinaryTree->leftNode, tmp);

	tmp = new Node;
	tmp->value = 7;
	insertRight(BinaryTree->rightNode, tmp);

	tmp = new Node;
	tmp->value = 8;
	insertLeft(BinaryTree->leftNode->rightNode, tmp);

	tmp = new Node;
	tmp->value = 9;
	insertRight(BinaryTree->rightNode->rightNode, tmp);

	cout << "\npreOrderTraversal: " << endl;
	preOrderTransversal(BinaryTree);
	cout << "\npostOrderTraversal: " << endl;
	postOrderTransversal(BinaryTree);
	cout << "\ninOrderTraversal: " << endl;
	inOrderTransversal(BinaryTree);

	cout << "searchResult: ";
	Node * searchResult = searchNode(BinaryTree, 9);
	if (searchResult != NULL){
		cout << "found 9" << endl;
	}
	searchResult = searchNode(BinaryTree, 8);
	if (searchResult != NULL) {
		cout << "found 8" << endl;
	}
	system("pause");
	return 0;
}
