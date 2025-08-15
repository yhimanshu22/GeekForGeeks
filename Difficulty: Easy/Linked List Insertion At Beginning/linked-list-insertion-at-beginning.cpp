class Solution {
  public:
    Node *insertAtBegining(Node *head, int x) {
        // Code here
        Node* newNode = new Node(x);
        if(head == NULL)return newNode;
        
        newNode->next = head;
        
        head = newNode;
        
        return head;
    }
};