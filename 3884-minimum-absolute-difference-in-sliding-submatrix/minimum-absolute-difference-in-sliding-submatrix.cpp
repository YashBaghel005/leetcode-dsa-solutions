class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1));

        for(int i = 0; i<m-k+1; i++){
            for(int j = 0; j<n-k+1; j++){
                set<int> s;
                for(int p = i; p<i+k; p++){
                    for(int q = j; q<j+k; q++){
                        s.insert(grid[p][q]);
                    }
                }
                vector<int> a(s.begin(),s.end());
                int mini = INT_MAX;
                for(int i = 0; i<a.size()-1; i++){
                    int x = a[i];
                    for(int j = i+1; j<a.size(); j++){
                        int y = a[j];
                        mini = min(mini,abs(x-y));
                    }
                }
                if(mini != INT_MAX)
                ans[i][j] = mini;
                else
                ans[i][j] = 0;
            }
        }
        return ans;
    }
};