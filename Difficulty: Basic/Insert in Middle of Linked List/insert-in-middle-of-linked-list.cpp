class Solution {
  public:
    Node *insertInMiddle(Node *head, int x) {
        Node* newNode = new Node(x);
        if (head == NULL) return newNode;

        // count nodes
        int cnt = 0;
        Node* temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }

        int mid = (cnt + 1) / 2;   // desired middle position
        temp = head;

        // move to node just BEFORE middle
        for (int i = 1; i < mid; i++) {
            temp = temp->next;
        }

        // insert
        newNode->next = temp->next;
        temp->next = newNode;

        return head;
    }
};
