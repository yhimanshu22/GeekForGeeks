// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/


class Solution {
  private:
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool isCBT(Node* root, int index, int total) {
        if (!root) return true;
        if (index >= total) return false; // violates CBT
        return isCBT(root->left, 2*index + 1, total) &&
               isCBT(root->right, 2*index + 2, total);
    }

    bool isMaxHeapProperty(Node* root) {
        if (!root) return true;

        if (root->left && root->data < root->left->data) return false;
        if (root->right && root->data < root->right->data) return false;

        return isMaxHeapProperty(root->left) && isMaxHeapProperty(root->right);
    }

  public:
    bool isHeap(Node* root) {
        int total = countNodes(root);
        return isCBT(root, 0, total) && isMaxHeapProperty(root);
    }
};
