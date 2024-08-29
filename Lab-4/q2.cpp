//using array
#include <iostream>
#include <cmath>
#define MAX_SIZE 1000
using namespace std;

int tree[MAX_SIZE];
int size = 0;

// Insertion
void insert(int value) {
    if (size == MAX_SIZE) {
        cout << "Binary tree is full" << endl;
        return;
    }
    tree[size++] = value;
}

// search
bool search(int value) {
    for (int i = 0; i < size; i++) {
        if (tree[i] == value) {
            return true;
        }
    }
    return false;
}

// delete
void remove(int value) {
    int index = -1;
    for (int i = 0; i < size; i++) {
        if (tree[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Element not found" << endl;
        return;
    }
    tree[index] = tree[--size];
}
//print
void printlist(){
    for (int i=0;i<size;i++){
        cout<<tree[i]<<" ";
    }
}

struct node{
    int data;
    node* left;
    node* right;

    node(int val): data(val), left(nullptr), right(nullptr){}
};

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

void in_order(node* root){
    if(root==nullptr){
        return;
    }
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);
}

node* search(node* root, int key) {
    if(root == nullptr){
        return nullptr;
    }
    if(root->data == key){
        return root;
    }
    node* t1 = search(root->left, key);
    if(t1 != nullptr) return t1;

    node* t2 = search(root->right, key);
    return t2;
}

node* minValueNode(node* root) {
    node* current = root;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

node* deleteNode(node* root, int key) {
    node* root_del=search(root, key);
    node* current=root;
    while(current->right!=nullptr){
        current=current->right;
    }
    root_del->data=current->data;
    delete current;
    return root;
}
int main() {
    // Insert elements into the binary tree
    insert(10);
    insert(5);
    insert(15);
    insert(7);
    insert(12);

    // Search for an element
    cout << "Searching for 7: " << (search(7) ? "Found" : "Not found") << endl;

    // Delete an element
    remove(15);
    
    //print list
    printlist();
    cout<<endl;


    node* root = createBinaryTree();
    
    cout << "In-order traversal of the binary tree: ";
    in_order(root);
    cout << endl;

    int key;
    cout << "Enter key to search in the binary tree: ";
    cin >> key;
    if(search(root, key)) {
        cout << key << " is present in the binary tree." << endl;
    } else {
        cout << key << " is not present in the binary tree." << endl;
    }
     
    int del;
    cout << "Enter key to delete in the binary tree: ";
    cin >> del;
    root=deleteNode(root,del);

    cout << "In-order traversal of the binary tree: ";
    in_order(root);
    cout << endl;
    
    return 0;

}

