/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preorder(Node* root) {
        // code here
        vector<int> ans;
        helper(root,ans);
        return ans;
    }
    
        void helper(Node* root,vector<int>& ans){
        if(root == nullptr)return;
        ans.push_back(root->data);
        helper(root->left,ans);
        helper(root->right,ans);
    }
};