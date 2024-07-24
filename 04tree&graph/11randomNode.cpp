// https://godbolt.org/z/qjPea9z6v

#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For srand()
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    int size;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr), size(1) {}
};

class BST {
public:
    TreeNode* root;

    BST() : root(nullptr) {
        srand(time(nullptr)); // Initialize random seed
    }

    // Helper function to update the size of the node
    void updateSize(TreeNode* node) {
        if (node != nullptr) {
            node->size = 1 + getSize(node->left) + getSize(node->right);
        }
    }

    // Get the size of the subtree rooted at node
    int getSize(TreeNode* node) {
        return node == nullptr ? 0 : node->size;
    }

    // Insert a new value into the BST
    TreeNode* insert(TreeNode* node, int val) {
        if (node == nullptr) {
            return new TreeNode(val);
        }
        if (val < node->val) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        updateSize(node);
        return node;
    }

    // Insert a value into the BST
    void insert(int val) {
        root = insert(root, val);
    }

    // Find a node with the given value
    TreeNode* find(TreeNode* node, int val) {
        if (node == nullptr || node->val == val) {
            return node;
        }
        if (val < node->val) {
            return find(node->left, val);
        } else {
            return find(node->right, val);
        }
    }

    // Find a node with the given value
    TreeNode* find(int val) {
        return find(root, val);
    }

    // Delete a node with the given value
    TreeNode* deleteNode(TreeNode* node, int val) {
        if (node == nullptr) return node;

        if (val < node->val) {
            node->left = deleteNode(node->left, val);
        } else if (val > node->val) {
            node->right = deleteNode(node->right, val);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            TreeNode* temp = minValueNode(node->right);
            node->val = temp->val;
            node->right = deleteNode(node->right, temp->val);
        }
        updateSize(node);
        return node;
    }

    // Delete a node with the given value
    void deleteNode(int val) {
        root = deleteNode(root, val);
    }

    // Find the minimum value node in the subtree rooted at node
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // In-order traversal of the BST
    void inOrder(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        inOrder(node->left, result);
        result.push_back(node->val);
        inOrder(node->right, result);
    }

    // Get a random node from the BST
    TreeNode* getRandomNode() {
        if (root == nullptr) return nullptr;
        int randomIndex = rand() % root->size;
        return getRandomNode(root, randomIndex);
    }

private:
    // Helper function to get a random node based on index
    TreeNode* getRandomNode(TreeNode* node, int index) {
        int leftSize = getSize(node->left);
        if (index < leftSize) {
            return getRandomNode(node->left, index);
        } else if (index == leftSize) {
            return node;
        } else {
            return getRandomNode(node->right, index - leftSize - 1);
        }
    }
};

int main() {
    BST bst;
    
    // Insert values into the BST
    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    // Print the BST structure (for verification)
    cout << "BST structure (in-order traversal): ";
    vector<int> inOrderResult;
    bst.inOrder(bst.root, inOrderResult);
    for (int val : inOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    // Get random nodes from the BST
    cout << "Random nodes: " << endl;
    for (int i = 0; i < 10; ++i) {
        TreeNode* randomNode = bst.getRandomNode();
        if (randomNode != nullptr) {
            cout << randomNode->val << " ";
        }
    }
    cout << endl;

    return 0;
}
