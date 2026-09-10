class Solution {
public:
    bool solve(vector<int>& nums,int idx,int sum,vector<vector<int>> &dp){
        if(sum < 0){
            return false;
        }
        if(sum == 0){
            return true;
        }
        if(idx >= nums.size()){
            return false;
        }
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }
        return dp[idx][sum] = solve(nums,idx+1,sum-nums[idx],dp) || solve(nums,idx+1,sum,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2 != 0){
            return false;
        }
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum/2+1,-1));
        bool ans = solve(nums,0,sum/2,dp);
        return ans;
    }
};