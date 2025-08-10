/*
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
/*
    Print elements of a linked list on console
    Head pointer input could be NULL as well for empty list
*/

class Solution {
  public:
    vector<int> printList(Node *head) {
        // code here
        Node* temp = head;
        vector<int> ans;
        
        while(temp != NULL){
            ans.push_back(temp->data);
            temp = temp->next;
        }
        
        return ans;
    }
};