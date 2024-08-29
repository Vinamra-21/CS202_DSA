#include<iostream>
using namespace std;
struct Node {
    char data;
    Node* next;
};

struct Stack {
    Node* top;
};

Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Stack* createStack() {
    Stack* stack =new Stack;
    stack->top = nullptr;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == nullptr;
}

void push(Stack* stack, char data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    Node* temp = stack->top;
    char data = temp->data;
    stack->top = temp->next;
    delete temp;
    return data;
}

int isMatching(string in_user) {
    Stack* stack = createStack();
    for (int i = 0; in_user[i] != '\0'; i++) {
        if (in_user[i] == '(' || in_user[i] == '{' || in_user[i] == '[') {
            push(stack, in_user[i]);
        } 
        else if (in_user[i] == ')' || in_user[i] == '}' || in_user[i] == ']') {
            if (isEmpty(stack)) {
                return 0; //not balanced
            }
            char topChar = pop(stack);
            if ((in_user[i] == ')' && topChar != '(') ||
                (in_user[i] == '}' && topChar != '{') ||
                (in_user[i] == ']' && topChar != '[')) {
                return 0; // Not balanced
            }
        }
    }
    return isEmpty(stack); // 1 if balanced, 0 otherwise
}

int main() {
    string in_user;
    cout<<"Enter the string:";
    cin>>in_user;
    printf("%s\n", isMatching(in_user) ? "Balanced" : "Not Balanced");
    return 0;
}

