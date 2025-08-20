class Solution {
  public:
    int minTime(vector<int>& arr1, vector<int>& arr2) {
        // code here.
        int n =arr1.size();
        int time1 = 0,time2 = 0;
        
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                time1 += arr1[i];
                time2 += arr2[i];
            }else{
                time1 += arr2[i];
                time2 += arr1[i];
            }
        }
        
        return min(time1,time2);
    }
};
