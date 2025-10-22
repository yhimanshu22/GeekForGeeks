/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
  Node* reverse(Node* head){
      Node* prev = nullptr;
      Node* curr = head;
      
      while(curr){
          Node* nextNode = curr->next;
          curr->next = prev;
          prev =curr;
          curr = nextNode;
      }
      return prev;
  }
  
    Node* addOne(Node* head) {
        head = reverse(head);

        Node* temp = head;
        
        int carry = 1; // we want to add 1
        
        while(temp && carry){
            
            int sum = temp->data + carry;
            
            temp->data = sum%10;
            
            carry = sum/10;
            
            if(!temp->next && carry){
                temp->next = new Node(carry);
                carry = 0;
                
            }
            temp =temp->next;
        }
        
        return reverse(head);
    }
};