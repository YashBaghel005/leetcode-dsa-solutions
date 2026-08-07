class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0){
            intervals.push_back(newInterval);
            return intervals;
        }
        int xs = newInterval[0];
        int xe = newInterval[1];
        vector<vector<int>> ans;
        vector<bool> cut(intervals.size(),false);
        for(int i = 0; i<intervals.size(); i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            if((a >= xs && a <= xe) || (b >= xs && b <= xe)||(a <= xs && b >= xe)){
                cut[i] = true;
                xs = min(xs,a);
                xe = max(xe,b);
            }
        }
        bool t = true;
        for(int i = 0; i<intervals.size(); i++){
            if(cut[i] && t){
                ans.push_back({xs,xe});
                t = false;
            }else if(!cut[i]){
                ans.push_back(intervals[i]);
            }
        }
        if(t){
            intervals.push_back(newInterval);
            sort(intervals.begin(),intervals.end());
            return intervals;
        }
        return ans;
    }
};