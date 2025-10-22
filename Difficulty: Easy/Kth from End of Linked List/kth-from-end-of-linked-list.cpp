/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node *first = head,*second = head;
        
        for(int i=0;i<k;i++){
          if(!first)return {-1};
          first = first->next;
        }
        
        while(first){
            first = first->next;
            second = second->next;
        }
        
        return second->data;
    }
};