#include<iostream>

using namespace std;

struct node{
    int data;
    node* left;
    node* right;

    node(int val): data(val),left(nullptr),right(nullptr){}
};

node* insert(node* root,int data ,int& comp_insert){
    if(root==nullptr){
        return new node(data);
    }
    comp_insert++;
    if(data<root->data){
        comp_insert++;
        root->left=insert(root->left,data,comp_insert);
    }
    else if(data>root->data){
        comp_insert++;
        root->right=insert(root->right,data,comp_insert);
    }
    return root;
}

node* search(node* root, int key,int& comp_search){
    while(root!=nullptr){
        comp_search++;
        if(key==root->data){
            comp_search++;
            return root;
        }
        else if(key<root->data){
            comp_search++;
            root=root->left;
        }
        else {
            comp_search++;
            root = root->right;
        }
    }
    comp_search++;
    return nullptr;

}

node* minValueNode(node* root,int& comp_del) {
    node* current = root;
    while (current->left != nullptr){
        comp_del++;
        current = current->left;}
    comp_del++;
    return current;
}


node* deleteNode(node* root, int key, int& comp_del) {
    if (root == nullptr) {
        return root;
    }
    comp_del++;
    if (key < root->data) {
        comp_del++;
        root->left = deleteNode(root->left, key, comp_del);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key, comp_del);
        comp_del++;
    } else {
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }
        node* temp = minValueNode(root->right,comp_del);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data, comp_del);
    }
    return root;
}
void in_order(node* root){
    if(root==nullptr){
        return;
    }
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}
int main() {
    int comp_del=0;
    int comp_insert=0;
    int comp_search=0;
    node* root = nullptr;

    //insert
    cout<<"Binary Search Tree"<<endl;
    int k;
    cout<<"number of elements:";
    cin>>k;
    for (int i=0;i<k;i++){
        int temp;
        cout<<"Element"<<(i+1)<<":";
        cin>>temp;
        root = insert(root, temp,comp_insert);
        cout<<"Insert comparisons:"<<comp_insert<<endl; 
    }

    cout << "Inorder Traversal(BST): ";
    in_order(root);
    cout << endl;
    
    //search
    int serkey;
    cout<<"Key to search:";
    cin>>serkey;
    node* foundNode = search(root,serkey , comp_search);
    if (foundNode != nullptr) {
        cout << "Key found: " << foundNode->data << endl;
    } else {
        cout << "Key not found." << endl;
    }
    cout << "Search comparisons: " << comp_search << endl;
    //delete
    int delkey;
    cout<<"Key to delete:";
    cin>>delkey;
    root = deleteNode(root, delkey, comp_del);
    cout << "Deletion comparisons: " << comp_del << endl;

    cout << "Inorder Traversal(BST): ";
    in_order(root);
    cout << endl;

    return 0;
}