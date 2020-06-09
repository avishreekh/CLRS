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

void inorder_traversal(Node* node){
	if(node == NULL){ return; }
	inorder_traversal(node->left);
	cout << node->key << " ";
	inorder_traversal(node->right);
}

void preorder_traversal(Node *node){
	if(node == NULL){ return; }
	cout << node->key << " ";
	preorder_traversal(node->left);
	preorder_traversal(node->right);
}

void postorder_traversal(Node *node){
	if(node == NULL){ return; }
	postorder_traversal(node->left);
	postorder_traversal(node->right);
	cout << node->key << " ";
}

int main(){
	
	Node *root = new Node(8);
	root->left = new Node(5);
	root->right = new Node(9);
	root->left->left = new Node(2);
	root->left->right = new Node(6);
	root->left->right->left = new Node(5);
	root->left->right->right = new Node(7);

	cout << "Inorder traversal: ";
	inorder_traversal(root);
	
	cout << "\nPreorder traversal: ";
	preorder_traversal(root);
	
	cout << "\nPostorder traversal: ";
	postorder_traversal(root);
	
	cout << '\n';

	return 0;
}