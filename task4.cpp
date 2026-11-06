#include <iostream>
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
	if (root == nullptr) return createNode(data);
	if (data < root->data) root->left = insert(root->left, data);
	else if (data > root->data) root->right = insert(root->right, data);
	return root;
}

template <typename T>
T findMin(Node<T>* root) {
	if (root->left == nullptr) return root->data;
	return findMin(root->left);
}

template <typename T>
T findMax(Node<T>* root) {
	if (root->right == nullptr) return root->data;
	return findMax(root->right);
}

int main() {
	Node<int>* root = nullptr;
	int values[] = { 70,30,50, 20, 40, 60, 80 };
	for (int val : values) root = insert(root, val);

	cout << "Minimum value: " << findMin(root) << endl;
	cout << "Maximum value: " << findMax(root) << endl;

	return 0;
}
