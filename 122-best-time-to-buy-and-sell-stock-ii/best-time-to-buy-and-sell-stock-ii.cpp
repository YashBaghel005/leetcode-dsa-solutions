class Solution {
public:
    int solve(int index,vector<int>& prices,int buy,int n, vector<vector<int>> &dp){
        if(index == n){
            return 0;
        }
        int profit = 0;
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
        if(buy){
            profit += max(-prices[index]+solve(index+1,prices,0,n,dp),solve(index+1,prices,1,n,dp));
        }else{
            profit += max(prices[index]+solve(index+1,prices,1,n,dp),solve(index+1,prices,0,n,dp));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        return solve(0,prices,1,prices.size(),dp);
    }
};