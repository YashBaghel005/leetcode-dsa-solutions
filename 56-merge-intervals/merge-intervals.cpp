class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int j = 0;
        int pa = intervals[0][0];
        int pb = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++){
            int ca = intervals[i][0];
            int cb = intervals[i][1];
            if(pb >= ca){
                pb = max(pb, cb);
            }else{
                ans.push_back({pa,pb});
                j = i;
                pa = intervals[j][0];
                pb = intervals[j][1];
            }
        }
        ans.push_back({pa,pb});
        return ans;
    }
};