set<int> setInsert(int arr[], int n) {
    set<int> s;
    
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    // Your code here to insert arr into s

    return s;
}

void setDisplay(set<int> s) {
    // Your code here to display elements of s
    for(auto it :s){
        cout << it << " ";
    }
    
    cout << endl;
}

void setErase(set<int>& s, int x) {
    // write if condition here
    if(s.find(x) != s.end()){
        s.erase(x);
         cout << "erased " << x;
    }
   
    else{
    // write else condition here
    cout << "not found";
        
    }

    cout << endl;
}