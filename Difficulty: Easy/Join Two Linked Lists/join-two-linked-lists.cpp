/*
class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* joinTheLists(Node* head1, Node* head2) {
        // code here
        Node* temp = head1;
        
        while(temp->next != nullptr){
            temp = temp->next;
        }
        
        temp->next = head2;
        
        return head1;
    }
};