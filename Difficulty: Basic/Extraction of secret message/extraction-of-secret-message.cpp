string ExtractMessage(string s) {
    // code here.
    int n = s.size();
    
    string ans;
    
    for(int i=0;i<n;){
        if(i+2 < n && s.substr(i,3) == "LIE"){
            if (!ans.empty() && ans.back() != ' ')
                ans += ' ';
                i+=3;
        }
        else{
            ans += s[i] ;
            i++;
        }
    }
    
    return ans;
}
