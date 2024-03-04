#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
};

Node* newNode(int key) {
    Node* node = new Node;
    node->key = key;
    node->left = node->right = nullptr;
    return node;
}

Node* insert(Node* root, int key) {
    if (!root) {
        return newNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }

        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

void inorderTraversal(Node* root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->key << " ";
        inorderTraversal(root->right);
    }
}

int main53() {
    Node* root = nullptr;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    std::cout << "Inorder traversal of the given tree: ";
    inorderTraversal(root);
    std::cout << std::endl;

    deleteNode(root, 20);
    std::cout << "Inorder traversal after deleting 20: ";
    inorderTraversal(root);
    std::cout << std::endl;

    deleteNode(root, 30);
    std::cout << "Inorder traversal after deleting 30: ";
    inorderTraversal(root);
    std::cout << std::endl;

    deleteNode(root, 50);
    std::cout << "Inorder traversal after deleting 50: ";
    inorderTraversal(root);
    std::cout << std::endl;

    return 0;
}