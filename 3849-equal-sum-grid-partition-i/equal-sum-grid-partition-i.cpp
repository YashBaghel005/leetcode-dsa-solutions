class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> col_sum;
        vector<long long> row_sum;
        for(int i = 0; i<m; i++){
            long long sum_row = 0;
            for(int j = 0; j<n; j++){
                sum_row+=grid[i][j];
            }
            row_sum.push_back(sum_row);
        }
        for(int j = 0; j<n; j++){
            long long sum_col = 0;
            for(int i = 0; i<m; i++){
                sum_col+=grid[i][j];
            }
            col_sum.push_back(sum_col);
        }
        vector<long long> col_psum(n);
        vector<long long> col_ssum(n);
        long long p_sum = 0;
        long long s_sum = 0;
        for(int i = 0; i<n; i++){
            p_sum+=col_sum[i];
            col_psum[i] = (p_sum);
            col_ssum[n-i-1]=(s_sum);
            s_sum+=col_sum[n-i-1];
        }
    
        for(int i = 0; i<n-1; i++){
            if(col_psum[i] == col_ssum[i]){
                return true;
            }
        }

        vector<long long> row_psum(m);
        vector<long long> row_ssum(m);
        p_sum = 0;
        s_sum = 0;
        for(int i = 0; i<m; i++){
            p_sum+=row_sum[i];
            row_psum[i] = (p_sum);
            row_ssum[m-i-1] = (s_sum);
            s_sum+=row_sum[m-i-1];
        }
       
        for(int i = 0; i<m-1; i++){
            if(row_psum[i] == row_ssum[i]){
                return true;
            }
        }
        return false;

    }
};