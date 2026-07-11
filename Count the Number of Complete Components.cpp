class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            for(auto it:edges){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            queue<int> qu;
            vector<int> vis(n, 0);
            vector<vector<int>> edge(n, vector<int> (n, 0));
            int ans = 0;
            for(int i = 0;i < n;i++){
                if(vis[i]) continue;
                qu.push(i);
                vis[i] = 1;
                int vertex = 1, edg = 0;
                while(!qu.empty()){
                    int ele = qu.front();
                    qu.pop();
                    for(auto adjac:adj[ele]){
                        if(!vis[adjac]) {
                            qu.push(adjac);
                            vis[adjac] = 1;
                            vertex++;
                        }
                        if(!edge[ele][adjac]) {
                            edg++;
                            edge[ele][adjac] = 1;
                            edge[adjac][ele] = 1;
                        }
                    }
                }
                if(edg == vertex*(vertex-1)/2) ans++;
            }
            return ans;
        }
    };

//Optimal 
// do we need edge vector (ans is no)

class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            for(auto it:edges){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            queue<int> qu;
            vector<int> vis(n, 0);
            int ans = 0;
            for(int i = 0;i < n;i++){
                if(vis[i]) continue;
                qu.push(i);
                vis[i] = 1;
                int vertex = 1, degreeSum = 0;
                while(!qu.empty()){
                    int ele = qu.front();
                    qu.pop();
                    for(auto adjac:adj[ele]){
                        degreeSum++;
                        if(!vis[adjac]) {
                            qu.push(adjac);
                            vis[adjac] = 1;
                            vertex++;
                        }
                    }
                }
                if(degreeSum == vertex*(vertex-1)) ans++;
            }
            return ans;
        }
    };