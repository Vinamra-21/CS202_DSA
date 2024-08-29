#include <iostream>
#include <limits>
using namespace std;

// Structure for a node in the linked list
struct Node {
    int col;
    int val;
    Node* next;

    Node(int c, int v) : col(c), val(v), next(nullptr) {}
};

// Structure for a linked list representing a row in the matrix
struct LinkedList {
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the end of the linked list
    void insert(int col, int val) {
        Node* newNode = new Node(col, val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};

// Function to perform dense matrix multiplication
void dense_matrix_multiply(int **A, int **B, int **result, int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            for (int k = 0; k < col1; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to convert a dense matrix to a linked list representation
void dense_to_linked_list(int **matrix, LinkedList linkedLists[], int m, int n) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] != 0) {
                linkedLists[i].insert(j, matrix[i][j]);
            }
        }
    }
}

// Function to perform matrix multiplication using linked list representations
void linked_list_matrix_multiply (LinkedList A[], LinkedList B[], int **result, int row1, int col1, int row2, int col2) {
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            Node* tempA = A[i].head;
            while (tempA) {
                Node* tempB = B[tempA->col].head;
                while (tempB) {
                    result[i][tempB->col] += tempA->val * tempB->val;
                    tempB = tempB->next;
                }
                tempA = tempA->next;
            }
        }
    }
}

int main() {
    int row1, col1, row2, col2;
    
    cout << "Enter the number of rows for matrix A: ";
    while (!(cin >> row1) || row1 <= 0) {
        cout << "Invalid input. Please enter a positive integer for the number of rows: ";
        cin.clear();
        cin.ignore (numeric_limits <streamsize> ::max(), '\n');
    }
    
    cout << "Enter the number of columns for matrix A: ";
    while (!(cin >> col1) || col1 <= 0) {
        cout << "Invalid input. Please enter a positive integer for the number of columns: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Enter the number of rows for matrix B: ";
    while (!(cin >> row2) || row2 <= 0) {
        cout << "Invalid input. Please enter a positive integer for the number of rows: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << "Enter the number of columns for matrix B: ";
    while (!(cin >> col2) || col2 <= 0) {
        cout << "Invalid input. Please enter a positive integer for the number of columns: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (col1 != row2) {
        cout << "Matrices are not compatible for multiplication." << endl;
        return 0;
    }
            
    int **A = new int*[row1];
    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < row1; ++i) {
        A[i] = new int[col1];
        for (int j = 0; j < col1; ++j) {
            while (!(cin >> A[i][j])) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    int **B = new int*[row2];
    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < row2; ++i) {
        B[i] = new int[col2];
        for (int j = 0; j < col2; ++j) {
            while (!(cin >> B[i][j])) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    // Create result matrix
    int **result = new int*[row1];
    for (int i = 0; i < row1; ++i) {
        result[i] = new int[col2]();
    }

    // Perform dense matrix multiplication
    dense_matrix_multiply(A, B, result, row1, col1, row2, col2);

    // Display the result of dense matrix multiplication
    cout << "Result of dense matrix multiplication:" << endl;
    for (int i = 0; i < row1; ++i) {
        for (int j = 0; j < col2; ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    // Clean up
    for (int i = 0; i < row1; ++i) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < row2; ++i) {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < row1; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 0;
}

