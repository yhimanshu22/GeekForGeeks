/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

#include <unordered_set>

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        if (!head) return head;

        unordered_set<int> seen; // store unique values
        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL) {
            // if data already seen → delete node
            if (seen.find(curr->data) != seen.end()) {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            } else {
                // mark as seen and move ahead
                seen.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};
