vector<int> Smallestonleft(int arr[], int n) {
    vector<int> ans;
    set<int> s;               // stores values seen so far (unique)

    for (int i = 0; i < n; ++i) {
        auto it = s.lower_bound(arr[i]); // first >= arr[i]
        if (it == s.begin()) {
            ans.push_back(-1);           // no element < arr[i]
        } else {
            --it;
            ans.push_back(*it);          // largest element < arr[i]
        }
        s.insert(arr[i]);
    }
    return ans;
}
