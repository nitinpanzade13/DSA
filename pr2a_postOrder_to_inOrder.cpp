#include <iostream>
#include <stack>
#include <cctype>  // for isdigit
using namespace std;

// Tree Node definition
struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create an expression tree from a postfix expression
TreeNode* constructExpressionTree(string postfix) {
    stack<TreeNode*> st;

    for (char ch : postfix) {
        // If operand, create a new node and push to stack
        if (isalnum(ch)) {
            TreeNode* node = new TreeNode(ch);
            st.push(node);
        }
        // If operator, pop two nodes, form a new tree with the operator as root
        else {
            TreeNode* node = new TreeNode(ch);
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
            st.push(node);
        }
    }

    // The root of the expression tree
    return st.top();
}

// Non-recursive In-order Traversal using stack
void inOrderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {
        // Reach the leftmost node
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
            // cout << curr->left;
        }

        // Current node is NULL, backtrack
        curr = st.top();
        st.pop();
        cout << curr->value << " ";  // Print the node value

        // Visit the right subtree
        curr = curr->right;
    }
}

int main() {
    string postfix ;
    cout<<"Enter postfix expression : ";
    cin>>postfix;
    
    
    TreeNode* root = constructExpressionTree(postfix);
    
    //string cToPostfix = postOrderTraversal(root);
    cout<<root;
    cout << "In-order Traversal (non-recursive): ";
    inOrderTraversal(root);
    cout << endl;

    return 0;
}
