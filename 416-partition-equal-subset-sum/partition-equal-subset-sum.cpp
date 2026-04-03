class Solution {
public:
    bool solve(vector<int> nums,int n,int sum,vector<vector<int>>& dp,int& count){
        if(n <= 0 || sum<0){
            return false;
        }if(sum == 0){
            count++;
            return true;
        }
        if(dp[n][sum] != -1){
            count++;
            return dp[n][sum];
        }
        if(nums[n-1] <= sum){
            return dp[n][sum] = solve(nums,n-1,sum-nums[n-1],dp,count) || solve(nums,n-1,sum,dp,count);
        }else{
            return dp[n][sum] = solve(nums,n-1,sum,dp,count);
        }
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;
        for(int i = 0; i<nums.size(); i++){
            target+=nums[i];
        }
        if (target % 2 != 0) return false;
        target = target/2;
        int count = 0;
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        bool ans = solve(nums,n,target,dp,count);
        
        return ans;
    }
};