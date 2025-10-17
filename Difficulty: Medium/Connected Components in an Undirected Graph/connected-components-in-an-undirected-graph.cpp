class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent); // path compression
    }
    
    void unionSet(int u, int v, vector<int>& parent) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu != pv) parent[pu] = pv; // merge sets
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<int> parent(V);
        for (int i = 0; i < V; i++) parent[i] = i;

        // Step 1: Union all connected nodes
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            unionSet(u, v, parent);
        }

        // Step 2: Group nodes by their parent
        unordered_map<int, vector<int>> componentsMap;
        for (int i = 0; i < V; i++) {
            int p = findParent(i, parent);
            componentsMap[p].push_back(i);
        }

        // Step 3: Convert map to vector<vector<int>>
        vector<vector<int>> components;
        for (auto& p : componentsMap) {
            components.push_back(p.second);
        }

        return components;
    }
};
