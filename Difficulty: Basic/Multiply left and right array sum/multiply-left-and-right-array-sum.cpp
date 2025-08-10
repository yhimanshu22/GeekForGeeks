//  Function to multiply the sum of first half of the array with the sum of second half
//  of the array
class Solution {
  public:
    int multiply(vector<int> &arr) {
        // code here
        int n = arr.size();
        int mid = (n)/2;
        
        //left
        int left = 0,right =0;
        for(int i=0;i<mid;i++){
            left = left + arr[i];
        }
        
      
        for(int i=mid;i<n;i++){
            right = right + arr[i];
        }
        
        return left*right;
        
    }
};