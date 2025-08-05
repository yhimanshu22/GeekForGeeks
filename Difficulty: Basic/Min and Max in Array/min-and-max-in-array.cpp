// User function Template for C++
class Solution {
  public:
    pair<int, int> getMinMax(vector<int> arr) {
        // code here
        pair<int,int> p;
        int min = INT_MAX,max = INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i] > max){
                max = arr[i];
            }
            if(arr[i] < min)min = arr[i];
        }
        return pair<int,int>(min,max);
        
    }
};