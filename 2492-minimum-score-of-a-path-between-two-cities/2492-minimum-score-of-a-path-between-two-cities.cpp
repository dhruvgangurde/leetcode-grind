class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> g(n + 1);
        for(int i = 0; i < roads.size(); i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            g[u].push_back({v, w});// for edge u -> v with cost w
            g[v].push_back({u, w});// for edge v -> u with cost w
        }
        vector<bool> visited(n + 1,false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int ans = INT_MAX;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto [neighbour, cost] : g[u]){
                ans = min(ans, cost);
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};