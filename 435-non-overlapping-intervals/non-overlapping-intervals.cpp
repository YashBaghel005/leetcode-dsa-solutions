class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            // if (a[0] != b[0])
            //     return a[0] < b[0];   
            return a[1] < b[1];      
        });

        int removal = 0;
        int a = -50001;
        int b = -50001;
        for(int i = 0; i<intervals.size(); i++){
            if(intervals[i][0] < b){
                removal++;
                continue;
            }

            a = intervals[i][0];
            b = intervals[i][1];
        }
        return removal;
    }
};