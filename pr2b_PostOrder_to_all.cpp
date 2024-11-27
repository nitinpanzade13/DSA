#include <iostream>
#include <stack>
#include <cctype>  
using namespace std;

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


TreeNode* constructExpressionTree(string postfix) {
    stack<TreeNode*> st;

    for (char ch : postfix) {
      
        if (isalnum(ch)) {
            TreeNode* node = new TreeNode(ch);
            st.push(node);
        }
       
        else {
            TreeNode* node = new TreeNode(ch);
            node->right = st.top(); st.pop();
            node->left = st.top(); st.pop();
            st.push(node);
        }
    }

    return st.top();
}

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.top(); st.pop();
        cout << curr->value << " ";

        if (curr->right) st.push(curr->right);
        if (curr->left) st.push(curr->left);
    }
}

void inOrderTraversal(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = ro ot;

    while (curr != nullptr || !st.empty()) {
        
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

       
        curr = st.top();
         st.pop();
        cout << curr->value << " ";  

        curr = curr->right;
    }
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) return;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* curr = st1.top(); st1.pop();
        st2.push(curr);

        if (curr->left) st1.push(curr->left);
        if (curr->right) st1.push(curr->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->value << " ";
        st2.pop();
    }
}
int main() {
    string postfix ; 
 
    cout<<"Enter any postfix expression : ";
    cin>>postfix;

    TreeNode* root = constructExpressionTree(postfix);

    cout << "In-order Traversal (non-recursive): ";
    inOrderTraversal(root);

    cout<<endl;
    cout << "Pre-order Traversal (non-recursive): ";
    preOrderTraversal(root);

    cout<<endl;
    cout << "Post-order Traversal (non-recursive): ";
    postOrderTraversal(root);

    cout << endl;

    return 0;
}
