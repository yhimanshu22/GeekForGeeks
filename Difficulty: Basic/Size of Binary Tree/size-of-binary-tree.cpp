/*

Definition for Binary Tree Node
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
    int getSize(Node* node) {
        // code here
        if(node == nullptr)return 0;
        
        if(node->left == nullptr && node->right ==  nullptr)return 1;
        
        return 1 + getSize(node->left) + getSize(node->right);
    }
};