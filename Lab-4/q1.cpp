#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX_LEVEL = 6; // Maximum level of the skip list
int comp=0;
// Node structure for skip list
struct Node {
    int value;
    Node** forward; // Array of forward pointers
};

// Skip list class
class SkipList {
private:
    Node* header; // Pointer to the header node
    int level; // Current level of the skip list

public:
    // Constructor
    SkipList() {
        header = new Node;
        header->forward = new Node*[MAX_LEVEL];
        for (int i = 0; i < MAX_LEVEL; ++i) {
            header->forward[i] = nullptr;
        }
        level = 0;
    }

    // Destructor
    ~SkipList() {
        Node* current = header->forward[0];
        while (current != nullptr) {
            Node* next = current->forward[0];
            delete[] current->forward;
            delete current;
            current = next;
        }
        delete[] header->forward;
        delete header;
    }

    // Function to generate a random level for a node
    int randomLevel() {
        int level = 1;
        while (rand() < RAND_MAX / 2 && level < MAX_LEVEL) {
            level++;
        }
        return level;
    }

    // Function to insert a value into the skip list
    void insert(int value) {
        Node* update[MAX_LEVEL];
        Node* current = header;

        // Find the appropriate position to insert the new node
        for (int i = level; i >= 0; --i) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
            }
            update[i] = current;
        }
        current = current->forward[0];

        // If the value already exists, return
        if (current != nullptr && current->value == value) {
            return;
        }

        // Generate a random level for the new node
        int newLevel = randomLevel();

        // If the new level is greater than the current level, update the update array
        if (newLevel > level) {
            for (int i = level + 1; i <= newLevel; ++i) {
                update[i] = header;
            }
            level = newLevel;
        }

        // Create a new node and update the forward pointers
        Node* newNode = new Node;
        newNode->value = value;
        newNode->forward = new Node*[newLevel + 1];
        for (int i = 0; i <= newLevel; ++i) {
            newNode->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = newNode;
        }
    }

    // Function to search for a value in the skip list
    bool search(int value) {
        Node* current = header;
        for (int i = level; i >= 0; --i) {
            while (current->forward[i] != nullptr && current->forward[i]->value < value) {
                current = current->forward[i];
                comp++;
            }
        }
        current = current->forward[0];
        return (current != nullptr && current->value == value);
    }

    // Function to display the skip list
    void display() {
        for (int i = level; i >= 0; --i) {
            Node* current = header->forward[i];
            std::cout << "Level " << i << ": ";
            while (current != nullptr) {
                std::cout << current->value << " ";
                current = current->forward[i];
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    srand(time(NULL)); // Seed for random number generator
    // Create a skip list object
    SkipList skipList;
    
    int n;
    cout << "Enter the number of elements to be inserted in the skip list: ";
    cin>>n;
    cout << "Enter the elements to be inserted in the skip list: ";
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        skipList.insert(x);
    }
    
    // Display the skip list
    skipList.display();

    // Search for a value in the skip list
    int value;
    cout << "Enter the value to search in the skip list: ";
    cin >> value;
    if (skipList.search(value)) {
        std::cout << "Value " << value << " found in the skip list." << std::endl;
        cout<<"No of comparisons "<<comp;

    } else {
        std::cout << "Value " << value << " not found in the skip list." << std::endl;
    }

    return 0;
}