class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;

        // Dummy nodes for 0s, 1s, and 2s
        Node* zeroD = new Node(0);
        Node* oneD = new Node(0);
        Node* twoD = new Node(0);

        Node *zero = zeroD, *one = oneD, *two = twoD;
        Node* curr = head;

        // Step 1: Separate nodes into three lists
        while (curr) {
            if (curr->data == 0) {
                zero->next = curr;
                zero = zero->next;
            } else if (curr->data == 1) {
                one->next = curr;
                one = one->next;
            } else { // curr->data == 2
                two->next = curr;
                two = two->next;
            }
            curr = curr->next;
        }

        // Step 2: Connect three lists
        zero->next = (oneD->next) ? oneD->next : twoD->next;
        one->next = twoD->next;
        two->next = nullptr;

        // Step 3: New head
        head = zeroD->next;

        // Free dummy nodes
        delete zeroD;
        delete oneD;
        delete twoD;

        return head;
    }
};
