#include <iostream>
using namespace std;

template <typename T>
struct Node {
	T data;
	Node* left;
	Node* right;
};

template <typename T>
Node<T>* nod(T data) {
	Node<T>* nn = new Node<T>();
	nn->data = data;
	nn->left = nullptr;
	nn->right = nullptr;
	return nn;
}

template <typename T>
Node<T>* insertdata(Node<T>* root, T data) {
	if (root == nullptr) {
		root = nod(data);
	}
	else if (data < root->data) {
		root->left = insertdata(root->left, data);
	}
	else if (data > root->data) {
		root->right = insertdata(root->right, data);
	}
	return root;
}

template <typename T>
bool searchdata(Node<T>* root, T data) {
	if (root == nullptr) {
		return false;
	}
	else if (data == root->data) {
		return true;
	}
	else if (data < root->data) {
		return searchdata(root->left, data);
	}
	else {
		return searchdata(root->right, data);
	}
}

template <typename T>
void transversal(Node<T>* root) {
	if (root != nullptr) {
		transversal(root->left);
		cout << root->data << " ";
		transversal(root->right);
	}
}

int main() {
	Node<int>* root = nullptr;

	root = insertdata(root, 10);
	root = insertdata(root, 20);
	root = insertdata(root, 30);
	root = insertdata(root, 20);
	root = insertdata(root, 10);

	cout << "Traversal: ";
	transversal(root);
	cout << endl;

	int datasearch;
	cout << "Enter the number to search for: ";
	cin >> datasearch;

	if (searchdata(root, datasearch)) {
		cout << datasearch << " found" << endl;
	}
	else {
		cout << datasearch << " not found" << endl;
	}

	return 0;
}
