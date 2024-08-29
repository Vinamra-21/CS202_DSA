#include <iostream>
using namespace std;

// Structure for node of linked list
struct Node {
    int data;   
    Node* next;
};

// Structure for stack implemented with linked list
struct Stack {
    Node* top;
    char name; 
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to create a new empty stack
Stack* createStack(char name) { 
    Stack* stack = new Stack;
    stack->top = nullptr;
    stack->name = name; 
    return stack;
}

// Function to check if stack is empty
bool isEmpty(Stack* stack) {
    return (stack->top == nullptr);
}

// Function to push a new element onto the stack
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout << "Error: Stack " << stack->name << " is empty\n"; // Updated to include stack name
        return -1;
    }
    int popped = stack->top->data;
    Node* temp = stack->top;
    stack->top = stack->top->next;
    delete temp;
    return popped;
}

// Function to move a disk from one pole to another
void moveDisk(Stack* from1, Stack* from2,Stack* from3, int disk) { 
    cout << "Move disk " << disk << " from " << from1->name << " to " << from3->name << endl; 
    Node* current= from1->top;
    cout<<"Stack A: ";
    int stackA[500];
    int a=0;
    while(current!=nullptr){
        stackA[a++]=current ->data;
        current=current->next;
    }
    for (int i=a-1;i>=0;i--){
        cout<<stackA[i]<<" ";
    }
    cout<<endl;

    current= from2->top;
    cout<<"Stack B: ";
    int stackB[500];
    int b=0;
    while(current!=nullptr){
        stackB[b++]=current ->data;
        current=current->next;
    }
    for (int i=b-1;i>=0;i--){
        cout<<stackB[i]<<" ";
    }
    cout<<endl;
    
    current= from3->top;
    cout<<"Stack C: ";
    int stackC[500];
    int c=0;
    while(current!=nullptr){
        stackC[c++]=current ->data;
        current=current->next;
    }
    for (int i=c-1;i>=0;i--){
        cout<<stackC[i]<<" ";
    }
    cout<<endl;
}

// Function to implement Tower of Hanoi recursively
void towerOfHanoiUtil(int disks, Stack* source, Stack* auxiliary, Stack* destination) {
    if (disks == 1) {
        int disk = pop(source);
        push(destination, disk);
        moveDisk(source,auxiliary, destination, disk); // Updated to pass source and destination stacks
        return;
    }

    towerOfHanoiUtil(disks - 1, source, destination, auxiliary);

    int disk = pop(source);
    push(destination, disk);
    moveDisk(source,auxiliary, destination, disk);

    towerOfHanoiUtil(disks - 1, auxiliary, source, destination);
}

// Function to solve Tower of Hanoi problem
void towerOfHanoi(int disks) {
    Stack* source = createStack('A'); 
    Stack* auxiliary = createStack('B');
    Stack* destination = createStack('C');

    // Push disks onto source stack
    for (int i = disks; i >= 1; --i) {
        push(source, i);
    }

    towerOfHanoiUtil(disks, source, auxiliary, destination);

    // Deallocate memory
    delete source;
    delete auxiliary;
    delete destination;
}

int main() {
    int disks;
    cout << "Enter the number of disks: ";
    cin >> disks;
    cout<<"Initial Stack"<<endl;
    cout<<"Stack A: ";
    for(int i=disks;i>0;i--){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Stack B: "<<endl;
    cout<<"Stack C: "<<endl;
    cout<<endl;

    towerOfHanoi(disks);

    return 0;
}
