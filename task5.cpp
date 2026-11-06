#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T data;
	Node* left;
	Node* right;
	Node(T val) : data(val), left(nullptr), right(nullptr) {}
};

template<typename T>
class BST {
public:
	Node<T>* root;
	BST() : root(nullptr) {}

	Node<T>* insert(Node<T>* node, T val) {
		if (!node) return new Node<T>(val);
		if (val < node->data) node->left = insert(node->left, val);
		else node->right = insert(node->right, val);
		return node;
	}

	Node<T>* findMin(Node<T>* node) {
		while (node && node->left) node = node->left;
		return node;
	}

	Node<T>* deleteNode(Node<T>* node, T val) {
		if (!node) return nullptr;
		if (val < node->data) node->left = deleteNode(node->left, val);
		else if (val > node->data) node->right = deleteNode(node->right, val);
		else {
			if (!node->left) {
				Node<T>* temp = node->right;
				delete node;
				return temp;
			}
			else if (!node->right) {
				Node<T>* temp = node->left;
				delete node;
				return temp;
			}
			else {
				Node<T>* temp = findMin(node->right);
				node->data = temp->data;
				node->right = deleteNode(node->right, temp->data);
			}
		}
		return node;
	}

	void inOrder(Node<T>* node) {
		if (node) {
			inOrder(node->left);
			cout << node->data << " ";
			inOrder(node->right);
		}
	}
};

int main() {
	BST<int> tree;
	int arr[] = { 10,20,40,45,50,80,26, 70 };
	for (int val : arr) tree.root = tree.insert(tree.root, val);

	cout << "Original in-order traversal: ";
	tree.inOrder(tree.root);
	cout << endl;

	int key;
	cout << "Enter value to delete: ";
	cin >> key;

	tree.root = tree.deleteNode(tree.root, key);

	cout << "In-order traversal after deletion: ";
	tree.inOrder(tree.root);
	cout << endl;

	return 0;
}
