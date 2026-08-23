class Solution {
public:
    bool solve(vector<int> &nums,int idx,int target,vector<vector<int>> &dp){
        if(target < 0){
            return false;
        }
        if(idx == nums.size() && target == 0){
            return true;
        }
        if(idx >= nums.size()){
            return false;
        }
        if(dp[idx][target] != -1){
            return dp[idx][target];
        }
        return dp[idx][target] = solve(nums,idx+1,target,dp)||solve(nums,idx+1,target-nums[idx],dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        return solve(nums,0,target,dp);
    }
};