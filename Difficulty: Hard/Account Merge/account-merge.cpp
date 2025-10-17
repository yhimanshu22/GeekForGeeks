// User function Template for C++

class Solution {
  public:
    // Find with path compression
    int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent); // fixed argument order
}

    
    // Union two sets
    void unionSet(int u, int v, vector<int>& parent) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) parent[pu] = pv;
    }

    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;

        unordered_map<string, int> emailToID;

        // Step 1: Union accounts with common emails
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToID.count(email)) {
                    unionSet(i, emailToID[email], parent);
                } else {
                    emailToID[email] = i;
                }
            }
        }

        // Step 2: Group emails by parent account
        unordered_map<int, set<string>> mergedEmails;
        for (auto &p : emailToID) {
            string email = p.first;
            int id = p.second;
            int root = findParent(id, parent);
            mergedEmails[root].insert(email);
        }

        // Step 3: Build result
        vector<vector<string>> result;
        for (auto &p : mergedEmails) {
            int id = p.first;
            vector<string> account;
            account.push_back(accounts[id][0]); // Name
            account.insert(account.end(), p.second.begin(), p.second.end()); // Sorted emails
            result.push_back(account);
        }

        return result;
    }
};
