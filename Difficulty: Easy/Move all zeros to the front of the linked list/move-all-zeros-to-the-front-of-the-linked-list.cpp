/* Linked List Node structure
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
class Solution {
public:
    void moveZeroes(struct Node*& head) {
        if (head == nullptr || head->next == nullptr) return;

        Node* curr = head;
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->data == 0 && curr != head) {
                // Remove from current position
                prev->next = curr->next;

                // Move to front
                curr->next = head;
                head = curr;

                // Move curr ahead after insertion
                curr = prev->next;
            } else {
                prev = curr;
                curr = curr->next;
            }
       }
    }

};