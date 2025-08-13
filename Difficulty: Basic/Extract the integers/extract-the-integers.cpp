vector<string> extractIntegerWords(string s) {
    // code here
    int n =s.size();
    vector<string> ans;
    
    for(int i=0;i<n;){
        if(isdigit(s[i])){
           string num;
           while(i < n && isdigit(s[i])){
            num += s[i];
            i++;
           }
         ans.push_back(num);
        }else{
            i++;
        }
    }
    return ans;
    
    
}