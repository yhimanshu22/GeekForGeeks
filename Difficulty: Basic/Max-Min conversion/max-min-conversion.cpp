long long performOperation(long long n) {
    // code here.
        string numStr = to_string(n);
        string maxStr = numStr;
        string minStr = numStr;
        
        // Replace 5 -> 6 for maximum
        for (char &c : maxStr) {
            if (c == '5') c = '6';
        }
        
        // Replace 6 -> 5 for minimum
        for (char &c : minStr) {
            if (c == '6') c = '5';
        }
        
        long long maxNum = stoll(maxStr);
        long long minNum = stoll(minStr);
        
        return maxNum + minNum;
}
