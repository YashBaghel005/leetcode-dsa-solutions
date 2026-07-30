class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        vector<vector<bool>> vis(n,vector<bool>(n,false));
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int val = t.first;
            int x = t.second.first;
            int y = t.second.second;
            if(x == n-1 && y == n-1){
                return max(val,grid[x][y]);
            }
            if(vis[x][y]){
                continue;
            }
            vis[x][y] = true;
            for(int i = 0;i<dirs.size(); i++){
                int x1 = x+dirs[i][0];
                int y1 = y+dirs[i][1];
                if(x1 < 0 || x1 >= n || y1 < 0 || y1 >= n){
                    continue;
                }
                pq.push({max(grid[x][y],val),{x1,y1}});
            }
        }
        return -1;
    }
};