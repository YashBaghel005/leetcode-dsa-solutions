class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> mat(m,vector<int> (n,0));
        int count = 0;
        int sum = 0;
        for(int i = 0; i<m; i++){
            sum += grid[i][0];
            mat[i][0] = sum;
            if(sum <= k){
                count++;
                
            }
        }
        sum = grid[0][0];
        for(int j = 1; j<n; j++){
            sum += grid[0][j];
            mat[0][j] = sum;
            if(sum <= k){
                count++;
                
            }
        }

        for(int i = 1; i<m; i++){
            for(int j = 1; j<n; j++){
                int a = grid[i][j] + mat[i-1][j] + mat[i][j-1]- mat[i-1][j-1];
                mat[i][j] = a;
                if(a<=k){
                    count++;
                    
                }
            }
        }
        return count;
    }
};