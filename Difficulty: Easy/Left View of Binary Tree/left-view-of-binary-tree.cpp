/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
 */

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int> ans;
        helper(root,0,ans);
        return ans;
        
    }
    
    void helper(Node* root,int level ,vector<int>& ans){
        if(root == nullptr)return;
        if(level == ans.size()){
           ans.push_back(root->data);
        }
        helper(root->left,level+1,ans);
        helper(root->right,level+1,ans);
      
        
    }
};