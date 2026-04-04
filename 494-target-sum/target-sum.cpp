class Solution {
public:
    int solve(vector<int>& nums, int target,int n,vector<vector<int>> &dp){
        if(n == 0 && target == 0){
            return 1;
        }
        else if(n == 0){
            return 0;
        }
        if(target+1000>2000 || target+1000<0){
            return 0;
        }
        if(dp[n][target+1000] != -1){
            return dp[n][target+1000];
        } 
        int a = solve(nums,target-nums[n-1],n-1,dp);
        int b = solve(nums,target+nums[n-1],n-1,dp);

        return dp[n][target+1000] = a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int> (2001,-1));
        int ans = solve(nums,target,n,dp);
        return ans;
    }
};