

string reverseString(string s) {
    reverse(s.begin(), s.end());
    string ans;
    unordered_set<char> seen;

    for (char c : s) {
        if (c == ' ') continue;          // skip spaces
        if (seen.count(c)) continue;     // skip duplicates
        ans.push_back(c);
        seen.insert(c);
    }

    return ans;
}