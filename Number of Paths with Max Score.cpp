class Solution {
    public:
        int mod = 1e9+7;
        pair<int, int> solve(int i, int j, vector<string>& board, vector<vector<pair<int, int>>>& dp){
            if(i == 0 && j == 0) return {0, 1};
            if(i < 0 || j < 0) return {0, 0};
            if(board[i][j] == 'X') return {0, 0};
            if(dp[i][j].first != -1 && dp[i][j].second != -1) return dp[i][j];
    
            pair<int, int> up = solve(i-1, j, board, dp);
            pair<int, int> left = solve(i, j-1, board, dp);
            pair<int, int> upleft = solve(i-1, j-1, board, dp);
            if(up.second) up.first += board[i][j]=='S' ? 0 : board[i][j]-'0';
            if(left.second) left.first += board[i][j]=='S' ? 0 : board[i][j]-'0';
            if(upleft.second) upleft.first += board[i][j]=='S' ? 0 : board[i][j]-'0';
            int bestScore = 0, bestPath = 0;
            if(up.first == left.first && up.first == upleft.first){
                bestScore = up.first;
                bestPath = up.second+left.second+upleft.second;
            }
            else if(up.first == left.first){
                bestScore = up.first;
                bestPath = up.second+left.second;
                if(upleft.first > up.first){
                    bestScore = upleft.first;
                    bestPath = upleft.second;
                }
            }
            else if(up == upleft){
                bestScore = up.first;
                bestPath = up.second+upleft.second;
                if(left.first > up.first){
                    bestScore = left.first;
                    bestPath = left.second;
                }
            }
            else if(upleft == left){
                bestScore = left.first;
                bestPath = left.second+upleft.second;
                if(up.first > left.first){
                    bestScore = up.first;
                    bestPath = up.second;
                }
            }
            else {
                bestScore = up.first;
                bestPath = up.second;
                if(left.first > bestScore) {
                    bestScore = left.first;
                    bestPath = left.second;
                }
                if(upleft.first > bestScore) {
                    bestScore = upleft.first;
                    bestPath = upleft.second;
                }
            }
            return dp[i][j] = {bestScore%mod, bestPath%mod};
        }
        vector<int> pathsWithMaxScore(vector<string>& board) {
            int n = board.size();
            vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n, {-1, -1}));
            pair<int, int> temp = solve(n-1, n-1, board, dp);
            return {temp.first, temp.second};
        }
    };