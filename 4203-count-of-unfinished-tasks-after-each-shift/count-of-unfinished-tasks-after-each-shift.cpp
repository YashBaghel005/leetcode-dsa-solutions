class Solution {
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
        vector<long long> presum;
        long long sum = 0;
        for(int x:tasks){
            sum+=x;
            presum.push_back(sum);
        }
        int n = tasks.size();
        vector<int> ans;
        long long offset = 0;
        for(int s:shifts){
            if(s+offset >= sum){
                ans.push_back(0);
                offset = 0;
            }else{
                offset += s;
                auto it = upper_bound(presum.begin(),presum.end(),offset);
                ans.push_back(n-distance(presum.begin(),it));
            }
        }
        return ans;
    }
};