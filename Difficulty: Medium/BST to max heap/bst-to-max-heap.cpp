#include <bits/stdc++.h>
using namespace std;

/* Node structure
struct Node {
    int data;
    Node *left, *right;
};
*/

class Solution {
private:
    void inorder(Node* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->data);
        inorder(root->right, vals);
    }

    void postorderFill(Node* root, vector<int>& vals, int& index) {
        if (!root) return;
        postorderFill(root->left, vals, index);
        postorderFill(root->right, vals, index);
        root->data = vals[index++]; // assign largest to smallest
    }

public:
    void convertToMaxHeapUtil(Node* root) {
        if (!root) return;

        vector<int> vals;
        inorder(root, vals);               // Step 1: collect sorted values
        int index = 0;
        postorderFill(root, vals, index);  // Step 2: assign values in Max Heap order
    }
};
