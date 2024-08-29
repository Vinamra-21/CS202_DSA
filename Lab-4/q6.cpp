#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
    int height;
};

node* newnode(int data){
    node* newnode=new node();
    newnode->data=data;
    newnode->left=nullptr;
    newnode->right=nullptr;
    newnode->height=1;
    return newnode;
}

int height(node* node){
    if(node==nullptr){
        return 0;
    }
    return node->height;
}

int getbalance(node* node){
    if(node==nullptr){
        return 0;
    }
    return height(node->left)-height(node->right);
}

node* rightrotate(node* y){
    node* x=y->left;
    node* T2=x->right;

    x->right=y;
    y->left=T2; 

    y->height=max(height(y->right),height(y->left))+1;
    x->height=max(height(x->left),height(y->right))+1;

    return x;
}

node* leftrotate(node* x){
    node* y=x->right;
    node* T2=y->left;

    y->left=x;
    x->right=T2;

    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;

    return y;
}

node* rotation(int &balance, node* &node, int data){
    if(balance>1 && data<node->left->data){
        return rightrotate(node);
    }
    if(balance<-1 && data>node->right->data){
        return leftrotate(node);
    }
    if(balance>1 && data>node->left->data){
        node->left=leftrotate(node->left);
        return rightrotate(node);
    }
    if(balance<-1 && data<node->right->data){
        node->right=rightrotate(node->right);
        return leftrotate(node);
    }
    return node;
}

node* insertnode(node* node ,int data){
    if(node==nullptr){
        return newnode(data);
    }
    if(data < node->data){
        node->left = insertnode(node->left, data);
    }
    else if(data > node->data){
        node->right = insertnode(node->right, data);
    }
    else{
        return node;
    }

    node->height=1+max(height(node->left),height(node->right));
    int balance=getbalance(node);

    return rotation(balance, node, data);
}

void inorder(node* node){
    if(node==nullptr){
        return;
    }
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

node* search(node* node,int data){
    if(node==nullptr || node->data==data){
        return node;
    }
    else if(node->data < data){
        return search(node->right, data);
    }
    else{
        return search(node->left, data);
    }
}

node* minValueNode(node* root) {
    node* current = root;
    while (current->left != nullptr){
        current = current->left;}
    return current;
}

node* deletenode(node* root,int key){
    if(root==nullptr){
        return root;
    }
    if(key>root->data){
        root->right = deletenode(root->right, key);
    }
    else if(key<root->data){
        root->left = deletenode(root->left, key);
    }
    else{
        if(root->left==nullptr||root->right==nullptr){
            node* temp = root->left ? root->left : root->right;
            if(temp==nullptr){
                temp = root;
                root = nullptr;
            }
            else{
                *root = *temp;
            }
            delete temp;
        }
        else{
            node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }

    if (root == nullptr)
        return root;
    
    root->height = 1 + max(height(root->left), height(root->right));
    int balance = getbalance(root);

    return rotation(balance, root, key);
}

int main() {
    node* root = nullptr;

    // Insertion
    root = insertnode(root, 10);
    root = insertnode(root, 20);
    root = insertnode(root, 30);
    root = insertnode(root, 40);
    root = insertnode(root, 50);
    root = insertnode(root, 25);

    cout << "Inorder traversal of the constructed AVL tree is:" << endl;
    inorder(root);
    cout << endl;

    // Deletion
    root = deletenode(root, 20);

    cout << "Inorder traversal after deletion of 20:" << endl;
    inorder(root);
    cout << endl;

    // Search
    int keyToSearch = 30;
    node* searchResult = search(root, keyToSearch);
    if (searchResult != nullptr)
        cout << keyToSearch << " found in the AVL tree." << endl;
    else
        cout << keyToSearch << " not found in the AVL tree." << endl;

    return 0;
}
