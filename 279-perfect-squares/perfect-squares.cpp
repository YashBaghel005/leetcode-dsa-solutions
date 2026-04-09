class Solution {
public:
    int solve(int target,vector<int>& nums,vector<int> &dp){
        if(target == 0){
            return 0;
        }else if(target < 0){
            return 10;
        }
        if(dp[target] != -1){
            return dp[target];
        }
        int ans = INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            int a = 1+solve(target-nums[i],nums,dp);
            ans = min(ans,a);
        }
        return dp[target] = ans;
    }
    int numSquares(int n) {
        int target = n;
        n = sqrt(n);
        vector<int> nums;
        for(int i = 1; i<=n; i++){
            nums.push_back(i*i);
        }
        vector<int> dp(target+1,-1);
        return solve(target,nums,dp);
    }
};