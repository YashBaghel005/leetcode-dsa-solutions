class Solution {
public:
    int solve(int n,int t,vector<int> &nums,vector<vector<int>> &dp){
        if(n == 0 && t == 0){
            return 1;
        }
        else if(n == 0){
            return 0;
        }
        if(t < -1000 || t > 1000) return 0;
        if(dp[n][t+1000] != -1){
            return dp[n][t+1000];
        }
        int a = solve(n-1,t-nums[n-1],nums,dp);
        int b = solve(n-1,t+nums[n-1],nums,dp);
        // if(a+b == 0){
        //     return 0;
        // }
        return dp[n][t+1000] = a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(2001,-1));
        return solve(nums.size(),target,nums,dp);
    }
};