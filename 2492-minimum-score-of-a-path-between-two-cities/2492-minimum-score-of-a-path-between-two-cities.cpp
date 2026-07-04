class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // adjacency list -> {neighbour, edge cost}
        vector<vector<pair<int, int>>> g(n + 1);
        // build the graph
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            g[u].push_back({v, w}); // for edge u -> v with cost w
            g[v].push_back({u, w}); // for edge v -> u with cost w
        }
        vector<bool> visited(n + 1, false);
        queue<int> q;
        q.push(1);// start BFS from city 1
        visited[1] = true;// mark city 1 as visited
        int ans = INT_MAX;// stores the minimum edge cost
        // BFS traversal
        while(!q.empty()) {
            int u = q.front();// current city
            q.pop();
            // visit all neighbours of current city
            for(auto [neighbour, cost] : g[u]) {
                ans = min(ans, cost); // update minimum edge cost
                // visit neighbour only once
                if(!visited[neighbour]) {
                    visited[neighbour] = true; // mark neighbour as visited
                    q.push(neighbour);         // add neighbour to queue
                }
            }
        }
        return ans; // minimum edge cost in the connected component of city 1
    }
};