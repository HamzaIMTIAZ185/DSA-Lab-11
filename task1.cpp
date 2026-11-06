#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data) {
	Node* nn = new Node();
	nn->data = data;
	nn->left = nullptr;
	nn->right = nullptr;
	return nn;
}

void inorder(Node* root) {
	if (root != nullptr) {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}

void preorder(Node* root) {
	if (root != nullptr) {
		cout << root->data << " ";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node* root) {
	if (root != nullptr) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
	}
}

int main() {
	Node* root = createNode(3);
	root->left = createNode(6);
	root->right = createNode(10);
	root->left->left = createNode(12);
	root->left->right = createNode(20);

	cout << "In-order Traversal: ";
	inorder(root);
	cout << endl;

	cout << "Pre-order Traversal: ";
	preorder(root);
	cout << endl;

	cout << "Post-order Traversal: ";
	postorder(root);
	cout << endl;

	return 0;
}
