#include <iostream>

using namespace std;

struct Node{
	int key;
	Node* left;
	Node* right;
	Node(int x){
		key = x;
		left = NULL;
		right = NULL;
	}
};

Node* find_minimum(Node* node){
	if(node == NULL){ return node; }
	
	Node* temp = node;
	while(temp->left != NULL){ temp = temp->left; }
	return temp;
}

Node* find_maximum(Node* node){
	if(node == NULL){ return node; }

	Node* temp = node;
	while(temp->right != NULL){ temp = temp->right; }
	return temp;
}

int main(){

	Node *root = new Node(8);
	root->left = new Node(5);
	root->right = new Node(9);
	root->left->left = new Node(2);
	root->left->right = new Node(6);
	root->left->right->left = new Node(5);
	root->left->right->right = new Node(7);

	Node *node = find_minimum(root);
	if(node != NULL)
		cout << "Minimum: " << node->key << '\n';
	else
		cout << "Empty tree\n";
	
	node = find_maximum(root);
	if(node != NULL)
		cout << "Maximum: " << node->key << '\n';
	else
		cout << "Empty tree\n";

	return 0;
}