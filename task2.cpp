#include<iostream>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node* left;
	Node* right;
};

template <typename T>
Node<T>* createNode(T data) {
	Node<T>* nn = new Node<T>();
	nn->data = data;
	nn->left = nullptr;
	nn->right = nullptr;
	return nn;
}

template <typename T>
Node<T>* insert(Node<T>* root, T data) {
	if (root == nullptr) {
		return createNode(data);
	}
	if (data < root->data) {
		root->left = insert(root->left, data);
	}
	else if (data > root->data) {
		root->right = insert(root->right, data);
	}
	return root;
}

template <typename T>
void inorderTraversal(Node<T>* root) {
	if (root != nullptr) {
		inorderTraversal(root->left);
		cout << root->data << " ";
		inorderTraversal(root->right);
	}
}

int main() {
	Node<int>* root = nullptr;
	int values[] = { 10, 20, 30, 5, 15, 25, 35 };
	for (int val : values) {
		root = insert(root, val);
	}
	cout << "In-order Traversal of BST: ";
	inorderTraversal(root);
	cout << endl;
	return 0;
}
