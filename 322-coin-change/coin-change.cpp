class Solution {
public:
    int solve(vector<int>& coins, int amount,int count,vector<int> &dp){
        if(amount == 0){
            return 0;
        }else if(amount < 0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        int ans = INT_MAX;
        for(int i = 0; i<coins.size(); i++){
            int a = solve(coins,amount-coins[i],count+1,dp);
            if(a!= INT_MAX)
            ans = min(a+1,ans);
        }
        
        
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = solve(coins,amount,0,dp);
        
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};