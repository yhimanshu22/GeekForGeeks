/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        // code here
         // Min-heap: {node value, Node*}
        auto cmp = [](Node* a, Node* b) { return a->data > b->data; };
        priority_queue<Node*, vector<Node*>, decltype(cmp)> pq(cmp);
        
        for(auto node:arr){
            if(node)pq.push(node);
        }
        
        Node* dummy = new Node(0);
        Node* tail = dummy;
        
        while(!pq.empty()){
            auto top = pq.top();pq.pop();
            tail->next = top;
            tail = tail->next;
            
            if(top->next)pq.push(top->next);
        }
        return dummy->next;
    }
};