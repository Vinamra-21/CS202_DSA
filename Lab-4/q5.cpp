#include<iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void pre_order(node* root){
    if(root==nullptr){
        return;
    }
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}
void post_order(node* root){
    if(root==nullptr){
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" "; 
}
void in_order(node* root){
    if(root==nullptr){
        return;
    }
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}


node* createBinaryTree() {
    int data;
    cout << "Enter root value (-1 for NULL): ";
    cin >> data;

    if (data == -1)
        return nullptr;

    node* root = new node(data);
    cout << "Enter left child of " << data << ": ";
    root->left = createBinaryTree();
    cout << "Enter right child of " << data << ": ";
    root->right = createBinaryTree();

    return root;
}

node* insert(node* root, int data) {
    if (root == nullptr) {
        return new node(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}


int main() {
    cout<<"Binary Tree"<<endl;
    node* rootBT = createBinaryTree();

    cout << "Peorder Traversal(BT): ";
    pre_order(rootBT);
    cout << endl;

    cout << "Inorder Traversal(BT): ";
    in_order(rootBT);
    cout << endl;

    cout << "Postorder Traversal(BT): ";
    post_order(rootBT);
    cout << endl;


    node* rootBST = nullptr;

    cout<<"Binary Search Tree"<<endl;
    int k;
    cout<<"number of elements:";
    cin>>k;
    for (int i=0;i<k;i++){
        int temp;
        cout<<"Element"<<(i+1)<<":";
        cin>>temp;
        rootBST = insert(rootBST, temp); 
    }
    
    cout << "Peorder Traversal(BST): ";
    pre_order(rootBST);
    cout << endl;

    cout << "Inorder Traversal(BST): ";
    in_order(rootBST);
    cout << endl;

    cout << "Postorder Traversal(BST): ";
    post_order(rootBST);
    cout << endl;

    return 0;
}
