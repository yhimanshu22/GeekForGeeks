int findLength(string s) {
    int i = s.length() - 1;
    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ') i--;
    // Count characters of last word
    int cnt = 0;
    while (i >= 0 && s[i] != ' ') {
        cnt++;
        i--;
    }
    return cnt;
}
