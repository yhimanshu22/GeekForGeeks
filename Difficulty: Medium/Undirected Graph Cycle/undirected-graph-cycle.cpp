class Solution {
public:
    int findParent(int node, vector<int>& parent) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node], parent); // Path compression
    }

    void unionNodes(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);

        if (pu == pv) return;

        // Union by rank
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int> parent(V), rank(V, 0);

        for (int i = 0; i < V; i++)
            parent[i] = i;

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];

            int pu = findParent(u, parent);
            int pv = findParent(v, parent);

            if (pu == pv) // same set => cycle
                return true;

            unionNodes(u, v, parent, rank);
        }

        return false;
    }
};
