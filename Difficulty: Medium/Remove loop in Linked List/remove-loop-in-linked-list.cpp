/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        if (!head || !head->next) return;

        Node *slow = head, *fast = head;

        // Step 1: Detect loop using Floyd’s cycle detection
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        // No loop detected
        if (slow != fast) return;

        // Step 2: Find start of loop
        slow = head;
        if (slow == fast) {
            // Special case: loop starts at head
            while (fast->next != slow) fast = fast->next;
        } else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Step 3: Remove loop
        fast->next = nullptr;
        
    }
};