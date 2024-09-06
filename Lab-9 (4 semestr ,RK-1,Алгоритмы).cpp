#include <iostream>

using namespace std;

template<typename T>
class BST {
private:
    struct Node {
        T value;
        Node* left;
        Node* right;

        Node(const T& value, Node* left = nullptr, Node* right = nullptr) 
            : value(value), left(left), right(right) {}
    };
    Node* root = nullptr;

public:
    BST() : root(nullptr) {
        clear(root);
    }


    void insert(const T& data) {
        root = insertElement(root, data);
    }

    Node* insertElement(Node* node, const T& data) {
        if (!node) {
            node = new Node(data);
            return node;
        }

        if (data < node->value)
            node->left = insertElement(node->left, data);
        else if (data > node->value)
            node->right = insertElement(node->right, data);

        return node;
    }

    void preorder(const Node* node) const {
        if (!node)
            return;

        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void inorder(const Node* node) const {
        if (!node)
            return;

        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    void postorder(const Node* node) const {
        if (!node)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }

    void printPreorder() const {
        preorder(root);
    }

    void printInorder() const {
        inorder(root);
    }

    void printPostorder() const {
        postorder(root);
    }

    void remove(const T& data) {
        root = removeElement(root, data);
    }

    Node* removeElement(Node* node, const T& data) {
        if (!node)
            return nullptr;

        if (data < node->value)
            node->left = removeElement(node->left, data);
        else if (data > node->value)
            node->right = removeElement(node->right, data);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* successor = findMin(node->right);

            node->value = successor->value;

            node->right = removeElement(node->right, successor->value);
        }

        return node;
    }

    Node* findMin(Node* node) const {
        while (node->left)
            node = node->left;
        return node;
    }


    bool search(const T& data) const {
        return searchElement(root, data);
    }

    bool searchElement(const Node* node, const T& data) const {
        if (!node)
            return false;

        if (data == node->value)
            return true;
        else if (data < node->value)
            return searchElement(node->left, data);
        else
            return searchElement(node->right, data);
    }

    bool contains(const T& data) const {
        return search(data);
    }

    void clear(Node* node) {
        if (!node)
            return;

        clear(node->left);
        clear(node->right);
        delete node;
    }
};

int main() {
    BST<string> tree;
    tree.insert("D");
    tree.insert("C");
    tree.insert("X");
    tree.insert("B");
    tree.insert("A");

    cout << "Preorder traversal: ";
    tree.printPreorder();

    return 0;
}
