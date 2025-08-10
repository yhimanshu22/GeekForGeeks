//User function Template for C++

class Solution{
    public:
    long long get_Sum(int n,vector<int>&input)
    {long long sum = 0;
        for(int i=0;i<n;i++){
            sum+=input[i];
        }
        return sum;
        
    }
};
