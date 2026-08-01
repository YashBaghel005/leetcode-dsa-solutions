class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end(),[](const vector<int> &a,const vector<int> &b){
            if(a[0] == b[0]){
                return a[1] < b[1];
            }else
                return a[0] < b[0];
        });
        int i = 0;
        int j = 1;
        int si = points[i][0];
        int ei = points[i][1];
        int arrow = 0;
        while(j < n){
            int sj = points[j][0];
            int ej = points[j][1];
            ei = min(ei,ej);
            if(ei < sj){
                i = j;
                si = points[i][0];
                ei = points[i][1];
                arrow++;
            }
            j++;
        }
        return arrow+1;
    }
};