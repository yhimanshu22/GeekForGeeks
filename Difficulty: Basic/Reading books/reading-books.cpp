// User function Template for C++

class Solution {
  public:
    int maxPoint(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        int n=arr1.size();
        int sum =0;
        for(int i=0;i<n;i++){
            int times = k/arr1[i];
            int points = arr2[i]*times;
            sum = max(points,sum);
        }
        
        return sum;
        
    }
};