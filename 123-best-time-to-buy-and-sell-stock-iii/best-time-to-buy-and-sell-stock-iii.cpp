class Solution {
public:
    int solve(vector<int>& nums,int idx,bool buy,int nt,vector<vector<vector<int>>> &dp){
        if(idx>=nums.size()){
            return 0;
        }else if(nt <= 0){
            return 0;
        }
        if(dp[idx][buy][nt] != -1){
            return dp[idx][buy][nt];
        }
        if(buy){
            return dp[idx][buy][nt] =  max(-nums[idx]+solve(nums,idx+1,false,nt,dp),solve(nums,idx+1,true,nt,dp));
        }else{
            return dp[idx][buy][nt] =  max(solve(nums,idx+1,false,nt,dp),nums[idx]+solve(nums,idx+1,true,nt-1,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,0,true,2,dp);
    }
};