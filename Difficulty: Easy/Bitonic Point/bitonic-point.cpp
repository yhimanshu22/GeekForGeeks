// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int l =0 ,r =n-1;
        
        while(l <= r){
            int mid = l + (r-l)/2;
            
            if((mid == 0 || arr[mid] > arr[mid-1]) && (mid == n-1 || arr[mid] > arr[mid+1])){
                return arr[mid];
            }
            
            if(arr[mid+1]>arr[mid]){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return -1;
    }
};