/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* head) {
        if(!head)return nullptr;
        
        Node* curr = head;
        
        while(curr->next){
            if(curr->data == curr->next->data){
                Node *temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }else{
                curr =curr->next;
            }
        }
        
        return head;
        
    }
};