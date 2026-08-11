class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // my approach 
        /*
            for -> 0->n for 0->n
                if(1)
                ans++;
                bfs
                0
        */
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        int noi = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == '1'){
                    noi++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';
                    while(!q.empty()){
                        auto t = q.front();
                        q.pop();
                        int x = t.first;
                        int y = t.second;
                        for(int i = 0; i<dirs.size(); i++){
                            int x1 = x + dirs[i][0];
                            int y1 = y+ dirs[i][1];
                            if(x1 >= m || x1 < 0 || y1 >=n || y1 < 0){
                                continue;
                            }
                            if(grid[x1][y1] == '1'){
                                q.push({x1,y1});
                                grid[x1][y1] = '0';
                            }
                        }
                    }
                }
            }
        }
        return noi;
    }
};