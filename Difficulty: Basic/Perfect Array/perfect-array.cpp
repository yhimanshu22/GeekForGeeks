class Solution {
  public:
    bool isPerfect(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        if(n==0)return true;
        
        int i=1;
        
        while(i < n && arr[i] > arr[i-1]){
            i++;
        }
        
        while(i < n && arr[i] == arr[i-1]){
            i++;
        }
        
        while(i < n && arr[i] < arr[i-1])i++;
        
        return i==n;
    }
};
