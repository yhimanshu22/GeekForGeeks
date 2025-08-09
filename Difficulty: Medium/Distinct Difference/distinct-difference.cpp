class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
        // code here
        set<int> left;
        set<int> right;
        vector<int> leftcnt(N,0);
        vector<int> rightcnt(N,0);
        
        for(int i=0;i<N;i++){
            leftcnt[i] = left.size();
            left.insert(A[i]);
        }
        
        for(int i=N-1;i>=0;i--){
            rightcnt[i] = right.size();
            right.insert(A[i]);
        }
        
        vector<int> ans(N);
        for(int i=0;i<N;i++){
            ans[i] = leftcnt[i] - rightcnt[i];
        }
        
        return ans;
    }
    
};
