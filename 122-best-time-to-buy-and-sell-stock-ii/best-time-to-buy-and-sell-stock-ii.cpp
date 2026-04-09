class Solution {
public:
    int solve(vector<int>& prices,int buy,int n,int index,vector<vector<int>> &dp){
        if(index == n){
            return 0;
        }
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        int profit = 0;
        if(buy){
            profit += max(-prices[index]+solve(prices,0,n,index+1,dp),solve(prices,1,n,index+1,dp));
        }else{
            profit += max(prices[index]+solve(prices,1,n,index+1,dp),solve(prices,0,n,index+1,dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(prices,1,n,0,dp);
    }
};