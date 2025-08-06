/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return helper(root,INT_MIN ,INT_MAX);
    }
    
    bool helper(Node* root , int min,int max){
        if(root == nullptr)return true;
        if(root->data <= min || root->data >= max){
            return false;
        }
        
        return helper(root->left,min,root->data) && helper(root->right,root->data,max);
    }
};