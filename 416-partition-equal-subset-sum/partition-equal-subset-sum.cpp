class Solution {
public:
    bool solve(vector<int>& nums,int target,int idx,vector<vector<int>> &dp){
        if(idx >= nums.size()){
            if(target == 0){
                return true;
            }
            return false;
        }if(target < 0){
            return false;
        }

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        bool ans = solve(nums,target-nums[idx],idx+1,dp) || solve(nums,target,idx+1,dp);
        return dp[idx][target] = ans;
    }
    bool canPartition(vector<int>& nums) {
        // sum calc
        // subset -> s -> sum/2
        /*
            include ya nahi include karo 
        */
        int sum = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(nums.size()+1,vector<int>(target+1,-1));
        bool ans = solve(nums,target,0,dp);
        return ans;
    }
};