class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row_s = 0;
        int row_e = matrix.size()-1;
        int col_s = 0;
        int col_e = matrix[0].size()-1;
        vector<int> ans;
        while(row_s <= row_e && col_s <= col_e){
            for(int i = col_s; i<=col_e; i++){
                ans.push_back(matrix[row_s][i]);
            }
            row_s++;
            if(row_s > row_e){
                break;
            }

            for(int i = row_s; i<=row_e; i++){
                ans.push_back(matrix[i][col_e]);
            }
            col_e--;
            if(col_s > col_e){
                break;
            }

            for(int i = col_e; i>=col_s; i--){
                ans.push_back(matrix[row_e][i]);
            }
            row_e--;
            if(row_s > row_e){
                break;
            }

            for(int i = row_e; i >= row_s; i--){
                ans.push_back(matrix[i][col_s]);
            }
            col_s++;
            
        }
        return ans;
    }
};