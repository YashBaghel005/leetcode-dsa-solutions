class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{-1,0},{0,-1},{0,1},{1,0}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),0));
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int time = t.first;
            int x = t.second.first;
            int y = t.second.second;
            if(x == grid.size()-1 && y == grid.size()-1){
                return time;
            }
            if(vis[x][y]){
                continue;
            }
            vis[x][y] = true;
            for(int i = 0; i<dirs.size(); i++){
                int x1 = x+dirs[i][0];
                int y1 = y+dirs[i][1];
                if(x1 >= grid.size() || x1 < 0 || y1 >= grid[0].size() || y1 < 0){
                    continue;
                }
                if(vis[x1][y1]){
                    continue;
                }
                pq.push({max(time,grid[x1][y1]),{x1,y1}});
            }
        }
        return -1;
    }
};