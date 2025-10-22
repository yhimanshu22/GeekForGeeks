/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
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
            prev = curr;
            curr = nextNode;
            
        }
        return prev;
    }
    
    bool isPalindrome(Node *head) {
        //  code here
        if(!head || !head->next)return true;
        
        Node *slow = head,*fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* secondHalf = reverse(slow->next);
        Node* firstHalf = head;
        
        Node* temp = secondHalf;
        
        while(temp){
            if(firstHalf->data != temp->data){
                slow->next = reverse(secondHalf);
                return false;
            }
            firstHalf = firstHalf->next;
            temp = temp->next;
        }
        slow->next = reverse(secondHalf);
        return true;
        
    }
};