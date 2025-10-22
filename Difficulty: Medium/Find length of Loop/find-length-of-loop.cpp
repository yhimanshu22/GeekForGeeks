class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if (!head) return 0;

        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect loop
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // loop detected
                // Step 2: Count nodes in loop
                int count = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }

        // No loop
        return 0;
    }
};
