#include<bits/stdc++.h>
using namespace std;

struct node
{
    int value;
    node* next;
    node* prev;
};
void insertionSort(node* head,int n)
{
    if (head == nullptr || head->next == nullptr) {
        return; 
    }

    node* current = head->next;
    while (current != nullptr) {
        int key = current->value;
        node* prevNode = current->prev;
        while (prevNode != nullptr && prevNode->value > key) {
            prevNode->next->value = prevNode->value;
            prevNode = prevNode->prev;
        }
        if (prevNode == nullptr) {
            head->value = key;
        } else {
            prevNode->next->value = key;
        }
        current = current->next;
    }

}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    node* head = nullptr;
    node* tail = nullptr;
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        
        node* newNode = new node;
        newNode->value = value;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        
    }
    
    insertionSort(head,n);
    node* current = head;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;

    
    
    return 0;
}

