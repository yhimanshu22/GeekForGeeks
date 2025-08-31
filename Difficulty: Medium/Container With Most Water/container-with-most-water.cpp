class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int maxWater = 0;
        int l = 0,r = arr.size()-1;
        while(l<=r){
            int width = r-l;
            int area = width*(min(arr[l],arr[r]));
            maxWater = max(maxWater,area);
            
            if(arr[l] < arr[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxWater;
    }
};