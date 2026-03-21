class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> mat = grid;
        for(int i = x; i<=x+k-1; i++){
            for(int j = y; j<=y+k-1; j++){
                mat[i][j] = grid[x+k-1-(i-x)][j];
            }
        }
        return mat;
    }
};