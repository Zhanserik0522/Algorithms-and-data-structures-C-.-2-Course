#include <iostream>
#include <algorithm> // for std::max

using namespace std;

template<typename T>
class AVL {
private:
    struct Node {
        T data;
        int h;
        Node* left;
        Node* right;

        Node(const T& data) : data(data), h(1), left(nullptr), right(nullptr) {}
    };

    Node* root = nullptr;

    int getH(Node* node) {
        return (node == nullptr) ? 0 : node->h;
    }

    int getBalanceFactor(Node* node) {
        if (node == nullptr)
            return 0;
        return getH(node->left) - getH(node->right);
    }

    Node* rRotation(Node* node) {
        Node* y = node->left;
        Node* beta = y->right;

        y->right = node;
        node->left = beta;

        node->h = 1 + max(getH(node->left), getH(node->right));
        y->h = 1 + max(getH(y->left), getH(y->right));

        return y;
    }

    Node* lRotation(Node* node) {
        Node* y = node->right;
        Node* beta = y->left;

        y->left = node;
        node->right = beta;

        node->h = 1 + max(getH(node->left), getH(node->right));
        y->h = 1 + max(getH(y->left), getH(y->right));

        return y;
    }

    Node* insert(const T& data, Node* node) {
        if (node == nullptr)
            return new Node(data);

        if (data < node->data)
            node->left = insert(data, node->left);
        else if (data > node->data)
            node->right = insert(data, node->right);

        node->h = 1 + max(getH(node->left), getH(node->right));

        int bf = getBalanceFactor(node);

        if (bf > 1 && data < node->left->data)
            return rRotation(node);
        else if (bf > 1 && data > node->left->data) {
            node->left = lRotation(node->left);
            return rRotation(node);
        }
        else if (bf < -1 && data > node->right->data)
            return lRotation(node);
        else if (bf < -1 && data < node->right->data) {000
            node->right = rRotation(node->right);
            return lRotation(node);
        }
        return node;
    }

    Node* findMin(Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, const T& data) {
        if (node == nullptr)
            return node;

        if (data < node->data)
            node->left = deleteNode(node->left, data);
        else if (data > node->data)
            node->right = deleteNode(node->right, data);
        else {
            if (node->left == nullptr || node->right == nullptr) {
                Node* temp = (node->left != nullptr) ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;

                delete temp;
            }
            else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        if (node == nullptr)
            return node;

        node->h = 1 + max(getH(node->left), getH(node->right));
        int bf = getBalanceFactor(node);

        if (bf > 1 && getBalanceFactor(node->left) >= 0)
            return rRotation(node);
        if (bf > 1 && getBalanceFactor(node->left) < 0) {
            node->left = lRotation(node->left);
            return rRotation(node);
        }
        if (bf < -1 && getBalanceFactor(node->right) <= 0)
            return lRotation(node);
        if (bf < -1 && getBalanceFactor(node->right) > 0) {
            node->right = rRotation(node->right);
            return lRotation(node);
        }

        return node;
    }

    bool contains(const T& data, Node* node) const {
        if (node == nullptr)
            return false;

        if (data == node->data)
            return true;
        else if (data < node->data)
            return contains(data, node->left);
        else
            return contains(data, node->right);
    }

    Node* search(const T& data, Node* node) const {
        if (node == nullptr || node->data == data)
            return node;

        if (data < node->data)
            return search(data, node->left);
        else
            return search(data, node->right);
    }

public:
    void insert(const T& data) {
        root = insert(data, root);
    }

    void remove(const T& data) {
        root = deleteNode(root, data);
    }

    bool contains(const T& data) const {
        return contains(data, root);
    }

    bool search(const T& data) const {
        return search(data, root) != nullptr;
    }
};

int main() {
    AVL<string> tree;
    tree.insert("C");
    tree.insert("A");
    tree.insert("B");

    cout << boolalpha;
    cout << "Contains A: " << tree.contains("A") << endl; 
    cout << "Contains D: " << tree.contains("D") << endl; 

    cout << "Search A: " << tree.search("A") << endl;
    cout << "Search D: " << tree.search("D") << endl; 

    return 0;
}
