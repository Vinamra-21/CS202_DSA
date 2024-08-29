#include <iostream>
#include <vector>

template<typename T>
class TreeNode {
public:
    T data;
    std::vector<TreeNode<T>*> children;

    TreeNode(const T& data) : data(data) {}

    ~TreeNode() {
        for (TreeNode<T>* child : children) {
            delete child;
        }
    }
};

template<typename T>
class Tree {
private:
    TreeNode<T>* root;

    void printHelper(TreeNode<T>* node, int depth) {
        if (node == nullptr) {
            return;
        }

        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << "|-- " << node->data << std::endl;

        for (TreeNode<T>* child : node->children) {
            printHelper(child, depth + 1);
        }
    }

public:
    Tree() : root(nullptr) {}

    ~Tree() {
        delete root;
    }

    TreeNode<T>* getRoot() const {
        return root;
    }

    void setRoot(TreeNode<T>* root) {
        this->root = root;
    }

    void print() {
        if (root == nullptr) {
            std::cout << "Tree is empty." << std::endl;
            return;
        }

        std::cout << "Tree structure:" << std::endl;
        printHelper(root, 0);
    }

    void buildTreeFromUserInput() {
        std::cout << "Enter the data for the root node: ";
        T rootData;
        std::cin >> rootData;

        TreeNode<T>* rootNode = new TreeNode<T>(rootData);
        root = rootNode;

        buildSubtreeFromUserInput(rootNode);
    }

    void buildSubtreeFromUserInput(TreeNode<T>* parentNode) {
        std::cout << "Enter the number of children for node " << parentNode->data << ": ";
        int numChildren;
        std::cin >> numChildren;

        for (int i = 0; i < numChildren; ++i) {
            std::cout << "Enter the data for child " << i + 1 << " of node " << parentNode->data << ": ";
            T childData;
            std::cin >> childData;

            TreeNode<T>* childNode = new TreeNode<T>(childData);
            parentNode->children.push_back(childNode);

            buildSubtreeFromUserInput(childNode);
        }
    }
};

int main() {
    Tree<int> tree;

    // Build tree from user input
    tree.buildTreeFromUserInput();

    // Print tree structure
    tree.print();

    return 0;
}