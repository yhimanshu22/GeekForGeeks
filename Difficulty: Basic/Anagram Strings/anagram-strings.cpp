// User function Template for C++
class Solution {
  public:
    int areAnagram(string S1, string S2) {
        // code here
          if(S1.size()!= S2.size())return 0;
          
          vector<int> freqS1(26, 0);
          vector<int> freqS2(26, 0);
          
          for(auto s1:S1)freqS1[s1 - 'a']++;
          for(auto s2:S2)freqS2[s2 - 'a']++;
          
          for(int i=0;i<freqS1.size();i++){
              if(freqS1[i] != freqS2[i])return 0;
          }
          
          return 1;
    }
};