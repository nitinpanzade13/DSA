#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    } 
};

Node* insert(Node* root, int data){
    if(root==nullptr){
        return new Node(data);
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(!temp->left){
            temp->left= new Node(data);
            break;
        }
        else {
            q.push(temp->left);
        }

        if (!temp->right)
        {
            temp->right=new Node(data);
            break;
        }
        else{
            q.push(temp->right);
        }
    }
    return root;
}

void display(Node* root){
    if(root==nullptr) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data <<" ";

        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    cout<<endl;
}

int findDepth(Node* root){
    if (root==nullptr) return 0;
    
    queue<Node*> q;
    q.push(root);
    int depth=0;

    while (!q.empty())
    {
        int size=q.size();
        depth++;
        
        for(int i=0;i<size;i++){
        Node* temp = q.front();
        q.pop();

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
        }
    }

    return depth;
}

void displayLeefNode(Node* root){
    if(root==nullptr) return ;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(!temp->left && !temp->right){
            cout<< temp->data << " ";
        }

        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    cout<< endl;
}

Node* copyTree(Node* root){
    if(root==nullptr) return nullptr;

    Node* newRoot = new Node(root->data);
    queue<pair<Node* , Node*>> q;

    q.push({root,newRoot});

    while(!q.empty()){
        Node* orgNode = q.front().first;
        Node* cpyNode = q.front().second;
        q.pop();

        if(orgNode->left){
            cpyNode->left = new Node(orgNode->left->data);
            q.push({orgNode->left,cpyNode->left}); 
        } 

        if(orgNode->right){
            cpyNode->right= new Node(orgNode->right->data);
            q.push({orgNode->right,cpyNode->right});
        }
    }
    return newRoot;
}


int main(){
    Node* root = nullptr;
    char choice; 
    int val;

    do{
        cout<<"Enter any option : "<< endl;
        cout<<"1. insert"<<endl;
        cout<<"2. display"<<endl;
        cout<<"3. find Depth"<<endl;
        cout<<"4. diplay leap nodes"<<endl;
        cout<<"5. Copy Tree"<<endl;
        cout<<"6. exit!"<<endl;

        cin>>choice;

        switch(choice){
            case "1" :
                cout<<"Enter any value : ";
                cin>>val;
                root=insert(root,val);
                cout<<endl;
                break;
            case '2' :
                display(root);
                cout<<endl;
                break;
            case '3' :
                cout<<"Depth of Tree : "<<findDepth(root);
                cout<<endl;
                break;
            case '4' : 
                cout<<"Leap Nodes : ";
                displayLeefNode(root);
                cout<<endl;
                break;
            case '5' :
                cout<<"Copied tree : ";
                display(copyTree(root));
                cout<<endl;
                break; 
            case '6' :
                cout<<"Exited !!"  ;  
                break;
            default :
                cout<<"Enter correct choice!";
                break;     
        }
    }while(choice!='6');

    return 0;
}
