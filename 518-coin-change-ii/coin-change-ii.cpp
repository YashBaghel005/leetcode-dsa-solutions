class Solution {
public:
    int solve(int amount,vector<int>& coins,int n,vector<vector<int>> &dp){
        if(amount < 0 || n >= coins.size()){
            return 0;
        }
        if(amount == 0){
            return 1;
        }
        if(dp[n][amount] != -1){
            return dp[n][amount];
        }
        int take = solve(amount-coins[n],coins,n,dp);
        int skip = solve(amount,coins,n+1,dp);
        return dp[n][amount] = take+skip;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size()+1,vector<int>(amount+1,-1));
        return solve(amount,coins,0,dp);
    }
};