class Solution {
  public:
    Node* rotate(Node* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find the length of the list
        Node* temp = head;
        int length = 1;
        while (temp->next) {
            temp = temp->next;
            length++;
        }

        // Step 2: Handle k > length
        k = k % length;
        if (k == 0) return head; // no rotation needed

        // Step 3: Find the kth node (new tail)
        Node* newTail = head;
        for (int i = 1; i < k; i++) {
            newTail = newTail->next;
        }

        // Step 4: New head is next of newTail
        Node* newHead = newTail->next;

        // Step 5: Break the list
        newTail->next = nullptr;

        // Step 6: Connect old tail to old head
        temp->next = head;

        return newHead;
    }
};
