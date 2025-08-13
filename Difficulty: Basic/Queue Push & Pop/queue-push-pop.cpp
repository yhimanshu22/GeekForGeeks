// User function Template for C++

// User function Template for C++

queue<int> _push(vector<int> &arr) {
   queue<int> q;
    for (int x : arr) {
        q.push(x);   // enqueue elements
    }
    return q;
}

void _pop(queue<int> &q) {
    // print front and dequeue for each element until it becomes empty
    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}