class Solution {
public:
    int solve(vector<int>& nums,int index,int n,int ft,vector<vector<int>> &dp){
        if(index >= n){
            return 0;
        }
        if(ft == 1 && index == n-1){
            return 0;
        }
        if(dp[index][ft] != -1){
            return dp[index][ft];
        }
        int profit = 0;
        if(index == 0){
            profit += max(nums[index]+solve(nums,index+2,n,1,dp),solve(nums,index+1,n,0,dp));
        }else
            profit = max(nums[index]+solve(nums,index+2,n,ft,dp),solve(nums,index+1,n,ft,dp));

        return dp[index][ft] = profit;
    }
    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(2,-1));
        return solve(nums,0,nums.size(),0,dp);
    }
};