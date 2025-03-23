class Solution {
public:
  

const int MOD = 1e9 + 7;
typedef long long ll;
typedef pair<ll, ll> pll; // (time, node)

int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pll>> graph(n);
    
    // Build adjacency list
    for (auto& road : roads) {
        int u = road[0], v = road[1], time = road[2];
        graph[u].push_back({v, time});
        graph[v].push_back({u, time});
    }

    vector<ll> dist(n, LLONG_MAX);  // Shortest time to reach each node
    vector<ll> ways(n, 0);          // Ways to reach each node with shortest time
    priority_queue<pll, vector<pll>, greater<pll>> pq; // Min-heap

    // Start from node 0
    dist[0] = 0;
    ways[0] = 1;
    pq.push({0, 0}); // (time, node)

    while (!pq.empty()) {
        auto [currTime, node] = pq.top();
        pq.pop();

        if (currTime > dist[node]) continue; // Ignore outdated paths

        for (auto [neighbor, travelTime] : graph[node]) {
            ll newTime = currTime + travelTime;

            // Found a shorter path
            if (newTime < dist[neighbor]) {
                dist[neighbor] = newTime;
                ways[neighbor] = ways[node]; // Reset count
                pq.push({newTime, neighbor});
            }
            // Found another shortest path
            else if (newTime == dist[neighbor]) {
                ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
            }
        }
    }

    return ways[n-1]; // Ways to reach the last node in shortest time
}

};