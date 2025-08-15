// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }

};
*/

Node *deleteAtPosition(Node *head, int pos) {
    // Your code here
        Node* temp = head;
        
        if(head == nullptr)return nullptr;
        
        if(pos == 1)return head->next;
    
        for(int i=1;temp != nullptr && i < pos - 1;i++){
            temp = temp->next;
        }
        
         if (temp == nullptr || temp->next == nullptr) {
            return head;
        }
        
        temp->next= temp->next->next;
        
        return head;
}