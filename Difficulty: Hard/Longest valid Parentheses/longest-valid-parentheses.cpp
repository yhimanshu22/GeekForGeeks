
class Solution {
  public:
    int maxLength(string& s) {
        // code here
          stack<int> st;
        st.push(-1);  // base index
        int maxLen = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty())
                    st.push(i);
                else
                    maxLen = max(maxLen, i - st.top());
            }
        }

        return maxLen;
    }
};