class Solution {
  public:
    int largest(vector<int> &arr) {
        int res = INT_MIN;
        // code here
        for(int i=0;i<arr.size();i++){
            if(arr[i]>res){
                res = arr[i];
            }
        }
        return res;
    }
};
