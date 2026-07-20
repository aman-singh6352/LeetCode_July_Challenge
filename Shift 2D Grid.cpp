class Solution {
    public:
        vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> newgrid;
            newgrid = grid;
            while(k--){
                int lastele = newgrid[m-1][n-1];
                for(int i = m-1;i >= 0;i--){
                    for(int j = n-1;j >= 0;j--){
                        if(i == 0 && j == 0) newgrid[i][j] = lastele;
                        else if(j == 0) newgrid[i][j] = newgrid[i-1][n-1];
                        else newgrid[i][j] = newgrid[i][j-1];
                    }
                }
            }
            return newgrid;
        }
    };

// Optimal Way
// just calculate the new index of each element

class Solution {
    public:
        vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
            int m = grid.size(), n = grid[0].size();
            vector<vector<int>> newgrid(m, vector<int>(n));
            for(int i = 0;i < m;i++){
                for(int j = 0;j < n;j++){
                    int newi = ((j+k)/n+i)%m;
                    int newj = (j+k)%n;
                    newgrid[newi][newj] = grid[i][j];
                }
            }
            return newgrid;
        }
    };


/* Java Code */

class Solution {
    public List<List<Integer>> shiftGrid(int[][] grid, int k) {
        int m = grid.length, n = grid[0].length;
        List<List<Integer>> newGrid = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            newGrid.add(new ArrayList<>(Collections.nCopies(n, 0)));
        }
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                int newi = ((j+k)/n+i)%m;
                int newj = (j+k)%n;
                newGrid.get(newi).set(newj, grid[i][j]);
            }
        }
        return newGrid;
    }
}