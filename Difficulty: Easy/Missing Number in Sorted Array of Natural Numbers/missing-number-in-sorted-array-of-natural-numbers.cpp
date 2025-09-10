class Solution {
  public:
    int missingNumber(vector<int>& arr) {
        // Code here
        int n=arr.size()+1;
        int sum1=n*(n+1)/2;
         
         int sum2=0;
        for(int a:arr){
            sum2 += a;
        }
        
        return sum1-sum2;
    }
};