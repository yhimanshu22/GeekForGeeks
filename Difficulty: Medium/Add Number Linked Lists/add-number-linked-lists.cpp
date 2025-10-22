class Solution {
  public:
    // Helper function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

  // Remove leading zeros
    Node* removeLeadingZeros(Node* head) {
        while (head && head->data == 0) head = head->next;
        return head ? head : new Node(0); // if all zeros, return single 0 node
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
 // Step 0: Remove leading zeros
        head1 = removeLeadingZeros(head1);
        head2 = removeLeadingZeros(head2);

        // Step 1: Reverse both lists
        head1 = reverse(head1);
        head2 = reverse(head2);

        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;

        // Step 2: Add corresponding nodes
        while (head1 || head2 || carry) {
            int sum = carry;
            if (head1) {
                sum += head1->data;
                head1 = head1->next;
            }
            if (head2) {
                sum += head2->data;
                head2 = head2->next;
            }

            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }

        // Step 3: Reverse the result list to restore forward order
        return reverse(dummy->next);
    }
};
