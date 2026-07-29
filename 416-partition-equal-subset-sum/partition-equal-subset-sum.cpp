class Solution {
public:
    bool solve(vector<int> nums, int idx, int sum,int target,vector<vector<int>> &dp){
        if(idx >= nums.size()){
            return false;
        }
        if(sum == target){
            return true;
        }else if(sum >= target){
            return false;
        }
        if(dp[idx][sum] != -1){
            return dp[idx][sum];
        }

        bool ans = solve(nums,idx+1,sum+nums[idx],target,dp)||solve(nums,idx+1,sum,target,dp);
        return dp[idx][sum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x:nums){
            sum+=x;
        }
        if(sum % 2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,-1));
        return solve(nums,0,0,target,dp);
    }
};