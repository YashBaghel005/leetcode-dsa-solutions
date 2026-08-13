class Solution {
public:
    int solve(vector<int> &nums,int target,int idx,vector<vector<int>> &dp){
        if(idx >= nums.size()){
            if(target == 0){
                return 1;
            }
            return 0;
        }

        if(dp[idx][20000+target] != -1){
            return dp[idx][20000+target];
        }

        int a = solve(nums,target+nums[idx],idx+1,dp);
        int b = solve(nums,target-nums[idx],idx+1,dp);
        return dp[idx][20000+target] = a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(41001,-1));
        return solve(nums,target,0,dp);
    }
};