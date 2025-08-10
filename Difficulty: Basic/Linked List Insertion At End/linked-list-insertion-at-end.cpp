/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
         Node* newNode = new Node(x);
        Node* temp = head;
        
        
        if(head == NULL){
            return newNode;
        }
        
        while(temp->next != NULL){
            temp = temp->next;
        }
        
       
        temp->next = newNode;
        
        return head;
    }
};