// User function Template for C++

class Solution {
  public:
    int minimumApple(vector<int>& arr) {
        // Complete the function
        set<int> st;
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        
        return st.size();
    }
};
