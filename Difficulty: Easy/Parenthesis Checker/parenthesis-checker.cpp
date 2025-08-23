class Solution {
  public:
    bool isBalanced(string& k) {
        stack<char> s;
        
        for (char c : k) {
            if (c == '(' || c == '{' || c == '[') {
                s.push(c);
            } else {
                if (s.empty()) return false;

                if ((s.top() == '(' && c == ')') ||
                    (s.top() == '{' && c == '}') ||
                    (s.top() == '[' && c == ']')) {
                    s.pop();
                } else {
                    return false;
                }
            }
        }
        
        return s.empty();
    }
};
