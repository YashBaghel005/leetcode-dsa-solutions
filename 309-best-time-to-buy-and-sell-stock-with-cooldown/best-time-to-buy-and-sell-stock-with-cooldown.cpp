class Solution {
public:
    int solve(vector<int> &nums,int idx,bool sell,vector<vector<int>> &dp){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx][sell] != -1){
            return dp[idx][sell];
        }
        if(sell){
            return dp[idx][sell] = max(-nums[idx]+solve(nums,idx+1,false,dp),solve(nums,idx+1,true,dp));
        }else{
            return dp[idx][sell] = max(+nums[idx]+solve(nums,idx+2,true,dp),solve(nums,idx+1,false,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return solve(prices,0,true,dp);
    }
};