class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it:roads){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        vector<int> vis(n+1, 0);
        queue<int> qu;
        qu.push(n);
        vis[n] = 1;
        int ans = INT_MAX;
        while(!qu.empty()){
            // just traverse all the component edges and find the minimun one
            int u = qu.front();
            qu.pop();
            for(auto adjac:adj[u]){
                int v = adjac.first;
                ans = min(ans, adjac.second);
                if(!vis[v]){
                    qu.push(v);
                    vis[v] = 1;
                }
            }
        }
        return ans;
    }
};