class Solution {
  public:
    int convertFive(int n) {
        string s = to_string(n);
        for (char &c : s) {
            if (c == '0') c = '5';
        }
        return stoi(s);
    }
};
