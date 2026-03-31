class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n = cost.size();
        if(n == 0 || n == 1){
            return cost[n];
        }

        vector<int> dp = cost;
        dp.push_back(0);
        for(int i = 2; i<=n; i++){
            dp[i] += min(dp[i-1],dp[i-2]);
        }
        return dp[n];
    }
};