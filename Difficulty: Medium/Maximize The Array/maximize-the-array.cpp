//Back-end complete function template for C++

class Solution{   
public:
    struct compare {
        bool operator()(vector<int> const &v1, vector<int> const &v2) {
            // not same element
            if (v1[0] != v2[0]) {
                // place large element first
                return v1[0] < v2[0];
            }
                // same element
            else {
                // from same array
                if(v1[1] == v2[1]){
                    // small index first
                    return v1[2] > v2[2];
                }
                // from diff array
                // give 2nd array priority
                return v1[1] != 2;

            }
        }
    };

    vector<int> maximizeArray(int arr1[], int arr2[], int n) {
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;
        for (int i = 0; i < n; i++) {
            vector<int> v(3);
            v[0] = arr1[i], v[1] = 1, v[2] = i;
            pq.push(v);
        }
        for (int i = 0; i < n; i++) {
            vector<int> v(3);
            v[0] = arr2[i], v[1] = 2, v[2] = i;
            pq.push(v);
        }

        vector<int> ans;
        vector<pair<int, int>> ans1, ans2;
        int lastSeen = -1;
        while (!pq.empty()) {
            auto v = pq.top();
            pq.pop();

            // only uniques allowed
            if (lastSeen == v[0]) {
                continue;
            }
            if (v[1] == 1) {
                ans1.emplace_back(v[2], v[0]);
            } else {
                ans2.emplace_back(v[2], v[0]);
            }
            lastSeen = v[0];
            if (ans1.size() + ans2.size() == n) {
                break;
            }
        }
        sort(ans1.begin(), ans1.end());
        sort(ans2.begin(), ans2.end());
        for (auto pp : ans2) {
            ans.push_back(pp.second);
        }
        for (auto pp : ans1) {
            ans.push_back(pp.second);
        }
        return ans;
    }
};

