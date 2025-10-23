class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        // code here
        priority_queue<int> left;
        priority_queue<int,vector<int>,greater<int>> right;
        
        vector<double> result;
        
        for(int num:arr){
            if(left.empty() || num <= left.top()){
                left.push(num);
            }else{
                right.push(num);
            }
            
            if(left.size() > right.size()+1){
                right.push(left.top());
                left.pop();
            }else if(right.size() > left.size()){
                left.push(right.top());
                right.pop();
            }
            
            double median;
            if(left.size() == right.size()){
                median = (left.top() + right.top())/2.0;
            }else{
                median = left.top();
            }
            result.push_back(median);
        }
        return result;
    }
};
