class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 1){
            return 1;
        }
        int i = 0;
        int j = 1;
        sort(points.begin(),points.end());
        int si = points[0][0];
        int ei = points[0][1];
        int arrow = 0;
        while(j < points.size()){
            int sj = points[j][0];
            int ej = points[j][1];
            if(ei >= sj){
                ei = min(ei,ej);
            }else{
                arrow++;
                i = j;
                si = points[i][0];
                ei = points[i][1];
            }
            j++;
            if(j == points.size()){
                arrow++;
                break;
            }
        }
        return arrow;
    }
};