// https://godbolt.org/z/ddeWvsGc7



#include <iostream>
#include <vector>
#include <deque>
#include <sstream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inOrder(TreeNode* root, vector<int> &result) {
    if (root == nullptr) {
        return;
    }
    inOrder(root->left, result);
    result.push_back(root->val);
    inOrder(root->right, result);
}

void weaveLists(deque<int> &first, deque<int> &second, vector<deque<int>> &results, deque<int> prefix) {
    if (first.empty() || second.empty()) {
        deque<int> result = prefix;
        result.insert(result.end(), first.begin(), first.end());
        result.insert(result.end(), second.begin(), second.end());
        results.push_back(result);
        return;
    }

    int headFirst = first.front();
    first.pop_front();
    prefix.push_back(headFirst);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    first.push_front(headFirst);

    int headSecond = second.front();
    second.pop_front();
    prefix.push_back(headSecond);
    weaveLists(first, second, results, prefix);
    prefix.pop_back();
    second.push_front(headSecond);
}

vector<deque<int>> allSequences(TreeNode* node) {
    vector<deque<int>> result;
    if (node == nullptr) {
        result.push_back(deque<int>());
        return result;
    }

    deque<int> prefix;
    prefix.push_back(node->val);

    vector<deque<int>> leftSeq = allSequences(node->left);
    vector<deque<int>> rightSeq = allSequences(node->right);

    for (auto &left : leftSeq) {
        for (auto &right : rightSeq) {
            vector<deque<int>> weaved;
            weaveLists(left, right, weaved, prefix);
            result.insert(result.end(), weaved.begin(), weaved.end());
        }
    }

    return result;
}

int main() {
    // Hardcoded input sequence
    vector<int> values = {3, 2, 5, 1, 4};

    TreeNode* root = nullptr;
    for (int val : values) {
        root = insert(root, val);
    }

    vector<int> inOrderResult;
    inOrder(root, inOrderResult);
    cout << "In-order traversal of BST: ";
    for (int val : inOrderResult) {
        cout << val << " ";
    }
    cout << endl;

    vector<deque<int>> sequences = allSequences(root);
    cout << "Number of sequences: " << sequences.size() << endl;
    for (auto &seq : sequences) {
        cout << "sequence: ";
        for (int val : seq) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
