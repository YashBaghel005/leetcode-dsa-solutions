class Solution {
public:
    int solve(int n,int t,vector<int> &nums){
        if(n == 0 && t == 0){
            return 1;
        }
        else if(n == 0){
            return 0;
        }
        int a = solve(n-1,t-nums[n-1],nums);
        int b = solve(n-1,t+nums[n-1],nums);

        return a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums.size(),target,nums);
    }
};