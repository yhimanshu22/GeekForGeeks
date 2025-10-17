class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int max_profit = 0;
        
        for(int i=1;i<arr.size();i++){
            int curr_profit = arr[i] - arr[i-1];
            if(curr_profit > 0)max_profit+=curr_profit;
        }
        return max_profit;
    }
};