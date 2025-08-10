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
    int getCount(Node* head) {
        // Code here
        int cnt = 1;
        Node* temp = head;
        
        while(temp->next != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};