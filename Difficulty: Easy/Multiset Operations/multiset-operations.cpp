multiset<int> multisetInsert(int arr[], int n) {
    multiset<int> s;
    // Insert elements into a multiset
    for(int i=0;i<n;i++){
        s.insert(arr[i]);
    }

    return s;
}

void multisetDisplay(multiset<int> s) {
    // Multiset display print elements
    for(auto it:s){
        cout << it << " ";
    }
    cout << endl;
}

void multisetErase(multiset<int>& s, int x) {
    // If and else condition to erase x from multiset
    if(s.find(x) != s.end()){
        s.erase(x);
        cout << "erased " << x;
    }else{
       cout << "not found"; 
    }
    cout << endl;
}