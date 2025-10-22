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
        int len=1;
        while(head->next){
            head=head->next;
            len++;
        }
        return len;
    }
};