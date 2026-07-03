class Solution {
    public:
        vector<vector<int>> direc = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        bool findSafeWalk(vector<vector<int>>& grid, int health) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> result(m, vector<int>(n, 1e9));
            result[0][0] = grid[0][0];
            deque<pair<int, pair<int, int>>> dq;
            dq.push_front({grid[0][0], {0, 0}});
            while(!dq.empty()){
                auto [cost, inner_pair] = dq.front();// always the minimum guy
                auto [i, j] = inner_pair;
                dq.pop_front();
                for(auto it:direc){
                    int l = it[0]+i, k = it[1] + j;
                    if(l < m && l >= 0 && k < n && k >= 0 && cost+grid[l][k] < result[l][k]){
                        if(grid[l][k] == 0) {
                            // push from front
                            dq.push_front({cost, {l, k}});
                        }
                        else {
                            // push back
                            dq.push_back({cost+1, {l, k}});
                        }
                        result[l][k] = cost+grid[l][k];
                        if(l == m-1 && k == n-1) return result[l][k] < health;
                    }
                }
            }
            return false;
        }
    };