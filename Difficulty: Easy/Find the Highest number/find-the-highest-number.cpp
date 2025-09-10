class Solution {
  public:
    int findPeakElement(vector<int>& a) {
        // Code here.
        int n = a.size();
        int low= 0,high=n-1;
        
        while(low < high){
            int mid = low + (high-low)/2;
            
            if(a[mid] < a[mid+1]){
                low = mid+1;
            }else {
                high = mid;
            }
        }
        return a[low];
    }
};
