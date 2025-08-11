class Solution {
  public:
    int gcd(int n, vector<int> arr) {
        // Your code goes here
        int res = arr[0];
        for(int i=1;i<n;i++){
            res = helper(res , arr[i]);
            if(res == 1)return 1;
        }
        
        return res;
    }
    
    int helper(int a ,int b){
        if(b == 0)return a;
        return helper(b , a%b);
    }
};
