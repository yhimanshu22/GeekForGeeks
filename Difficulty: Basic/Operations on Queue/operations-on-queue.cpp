// User function Template for C++

class Solution {
  public:

    // Function to push an element in queue.
    void enqueue(queue<int> &q, int x) {
        // Your code here
        q.push(x);
        
    }

    // Function to remove front element from queue.
    void dequeue(queue<int> &q) {
     if(!q.empty())q.pop();
    }

    // Function to find the front element of queue.
        
    int front(queue<int> &q) {
         if(!q.empty()){
            return q.front();
        }
        return -1;
    }

        
    // Function to find an element in the queue.
    bool find(queue<int> q, int y) {
        // Your code here
        while(!q.empty()){
            if(q.front() == y){
                return true;
            }
            
            q.pop();
        }
        
        return false;
    }
};