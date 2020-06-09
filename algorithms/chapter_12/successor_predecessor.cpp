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

//This function can be avoided if the nodes are augmented with a pointer to parent
Node* find_parent(Node* root, Node* node){
	Node* parent = root;
	while(parent != NULL && parent->left != node && parent->right != node){
		if(node->key < parent->key){ parent = parent->left; }
		else{ parent = parent->right; }
	}
	return parent;
}

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

Node* find_successor(Node* root, Node* node){
	if(node->right != NULL){ return find_minimum(node->right); }
	
	Node* temp = node;
	Node* parent = find_parent(root, node);
	while(parent != NULL && temp == parent->right){
		temp = parent;
		parent = find_parent(root, parent);
	}

	return parent;
}

Node* find_predecessor(Node* root, Node* node){
	if(node->left != NULL){ return find_maximum(node->left); }

	Node* temp = node;
	Node* parent = find_parent(root, node);

	while(parent != NULL && temp == parent->left){
		temp = parent;
		parent = find_parent(root, parent);
	}

	return parent;
}

int main(){

	Node *root = new Node(8);
	root->left = new Node(5);
	root->right = new Node(9);
	root->left->left = new Node(2);
	root->left->right = new Node(6);
	root->left->right->left = new Node(5);
	root->left->right->right = new Node(7);

	Node *node = find_successor(root, root->left->right->right);
	if(node != NULL)
		cout << "Successor: " << node->key << '\n';
	else
		cout << "No successor\n";

	node = find_predecessor(root, root);
	if(node != NULL)
		cout << "Predecessor: " << node->key << '\n';
	else
		cout << "No Predecessor\n";

	return 0;
}