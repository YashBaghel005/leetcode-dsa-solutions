class Solution {
public:
    int solve(vector<int>& nums,int idx,bool first,vector<vector<int>> &dp){
        if(first && idx >= nums.size()-1){
            return 0;
        }
        if(idx >= nums.size()){
            return 0;
        } 
        if(dp[idx][first] != -1){
            return dp[idx][first];
        }
        int a = nums[idx] + solve(nums,idx+2,first,dp);
        int b = solve(nums,idx+1,first,dp);
        return dp[idx][first] = max(a,b);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        vector<vector<int>> dp(nums.size(),vector<int> (2,-1));
        return max(solve(nums,0,true,dp),solve(nums,1,false,dp));
    }
};