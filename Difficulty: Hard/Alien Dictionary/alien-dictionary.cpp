class Solution {
public:
    string findOrder(vector<string> &words) {
        int n = words.size();
        vector<int> adj[26];
        vector<int> indegree(26, 0);
        vector<bool> present(26, false);

        // Step 1: mark all characters present
        for(auto &word : words)
            for(char c : word)
                present[c - 'a'] = true;

        // Step 2: build graph
        for(int i = 0; i < n - 1; i++) {
            string &w1 = words[i], &w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            bool found_diff = false;

            for(int j = 0; j < len; j++) {
                if(w1[j] != w2[j]) {
                    adj[w1[j] - 'a'].push_back(w2[j] - 'a');
                    indegree[w2[j] - 'a']++;
                    found_diff = true;
                    break;
                }
            }

            // Check invalid case: prefix problem
            if(!found_diff && w1.size() > w2.size())
                return ""; // invalid ordering
        }

        // Step 3: Kahn's topo sort
        queue<int> q;
        for(int i = 0; i < 26; i++)
            if(present[i] && indegree[i] == 0) q.push(i);

        string order;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            order += (u + 'a');

            for(int v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) q.push(v);
            }
        }

        // Step 4: check cycle
        for(int i = 0; i < 26; i++)
            if(present[i] && indegree[i] > 0) return "";

        return order;
    }
};
