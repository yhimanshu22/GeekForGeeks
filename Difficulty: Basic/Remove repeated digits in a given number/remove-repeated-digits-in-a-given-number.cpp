
long long int modify(long long int N) {
    // your code here
    string s = to_string(N);
    string result;
    
    for (int i = 0; i < (int)s.length(); i++) {
        if (i == 0 || s[i] != s[i - 1]) {
            result.push_back(s[i]);
        }
    }
    
    return stoll(result);
}