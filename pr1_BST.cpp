#include <iostream>
#include <queue> // For BFS
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Insert a node in the BST
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        root = createNode(data);
    } else if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// In-order display of the BST (sorted order)
void inorderDisplay(Node* root) {
    if (root != nullptr) {
        inorderDisplay(root->left);
        cout << root->data << " ";
        inorderDisplay(root->right);
    }
}

// Search a node in the BST
Node* search(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Find the minimum value node
Node* findMin(Node* root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// Delete a node from the BST
Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// BFS (Level order traversal)
void bfs(Node* root) {
    if (root == nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main() {
    Node* root = nullptr;
    char choice;
    int value;

    do {
        cout << "\n1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Display (In-order)";
        cout << "\n4. Search";
        cout << "\n5. BFS (Level-wise Print)";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case '2':
                cout << "Enter value to delete: ";
                cin >> value;
                root = deleteNode(root, value);
                break;
            case '3':
                cout << "In-order traversal: ";
                inorderDisplay(root);
                cout << endl;
                break;
            case '4':
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value) != nullptr)
                    cout << "Value found!" << endl;
                else
                    cout << "Value not found!" << endl;
                break;
            case '5':
                cout << "Level-wise BFS: ";
                bfs(root);
                cout << endl;
                break;
            case '6':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}
