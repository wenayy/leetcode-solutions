class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        parent[y] = x;
    }

    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        parent.resize(n);
        vector<int> cost(n, -1); // Initialize cost to -1
        iota(parent.begin(), parent.end(), 0); // Initialize parent array

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int parent_u = find(u);
            int parent_v = find(v);

            if (parent_u != parent_v) {
                cost[parent_u] &= cost[parent_v]; // Update cost of parent_u with cost of parent_v
                Union(parent_u, parent_v);        // Merge parent_v into parent_u
                             // Update cost of parent_u with the current edge weight
            }  
                cost[parent_u] &= w;             // If both nodes are in the same component, update the cost
            
        }

        vector<int> result;
        for (auto& q : query) {
            int s = q[0];
            int t = q[1];

            int parent_s = find(s);
            int parent_t = find(t);

            if (s == t) {
                result.push_back(0);
            } else if (parent_s != parent_t) {
                result.push_back(-1);
            } else {
                result.push_back(cost[parent_s]);
            }
        }

        return result;
    }
};