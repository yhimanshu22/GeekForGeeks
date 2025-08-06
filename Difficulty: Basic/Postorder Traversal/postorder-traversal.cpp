/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */
class Solution {
  public:
    // Function to return a list containing the postorder traversal of the tree.
    vector<int> postOrder(Node* root) {
        // Your code here
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
    
    void helper(Node* root ,vector<int>& ans){
        if(root == nullptr)return;
        
        helper(root->left, ans);
        helper(root->right,ans);
        
        ans.push_back(root->data);
    }
    
};