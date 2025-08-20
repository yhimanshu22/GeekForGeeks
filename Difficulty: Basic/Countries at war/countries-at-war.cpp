// Function to determine which country is at war
class Solution {

  public:
    string countryAtWar(vector<int>& arr1, vector<int>& arr2) {
        int alive1 = 0 ,alive2 = 0;
        
        int n = arr1.size();
        
        for(int i=0;i<n;i++){
            if(arr1[i] > arr2[i])alive1++;
            if(arr1[i] < arr2[i])alive2++;
        }
        
        if(alive1 > alive2)return "A";
        if(alive1 < alive2)return "B";
        return "DRAW";
    }
};