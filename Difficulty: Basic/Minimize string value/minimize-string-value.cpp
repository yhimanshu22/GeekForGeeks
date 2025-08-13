// User function template for C++
class Solution {
  public:
    int minValue(string S, int K) {
        // Your code goes here
        unordered_map<char ,int> freq;
        
        for(auto c:S){
            freq[c]++;
        }
        
        priority_queue<int> pq;
        for(auto f:freq){
            pq.push(f.second);
        }
        
        while(K-- && !pq.empty()){
            int top = pq.top();
            pq.pop();
            top--;
            
            if(top > 0)pq.push(top);
        }
        
        
        int sum = 0;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            sum = sum + top*top;
        }
        
        return sum;
    }
};