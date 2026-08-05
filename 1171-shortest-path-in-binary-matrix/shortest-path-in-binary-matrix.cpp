class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1){
            if(grid[0][0] == 1)
                return -1;

            return 1;
        }
        vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({1,{0,0}});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int path = t.first;
            int x = t.second.first;
            int y = t.second.second;
            if(x == n-1 && y == n-1){
                return path;
            }
            if(grid[x][y] == 1){
                continue;
            }
            grid[x][y] = 1;
            for(int i = 0; i<dirs.size(); i++){
                int x1 = x+dirs[i][0];
                int y1 = y+dirs[i][1];

                if(x1 < 0 || x1 >=n || y1 < 0 || y1 >=n){
                    continue;
                }
                if(grid[x1][y1] == 1){
                    continue;
                }
                pq.push({path+1,{x1,y1}});
            }
        }
        return -1;
    }
};