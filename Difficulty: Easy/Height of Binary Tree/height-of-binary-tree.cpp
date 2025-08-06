/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int height(Node* node) {
        // code here
        return helper(node)-1 ;
    }
    
    int helper(Node* root){
        if(root == nullptr)return 0;
        
        int lh = helper(root->left);
       
        int rh = helper(root->right);
        
        return 1 + max(lh,rh);
        
    }
};