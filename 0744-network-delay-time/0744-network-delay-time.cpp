class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Initialize distance vector with a large value
        vector<int> dist(n + 1, 1e8);
        dist[k] = 0;  // Start node distance is 0

        // Relax edges (n - 1) times
        for (int i = 0; i < n - 1; i++) {
            for (auto it : times) {
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative weight cycles
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                return -1; // Negative cycle detected
            }
        }

        // Find the maximum distance in the dist array
        int maxDist = -1;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e8) {
                return -1; // If any node is not reachable, return -1
            }
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist;
    }
};