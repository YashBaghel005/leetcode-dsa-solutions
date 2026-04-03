class Solution {
public:
    void solve(vector<int>& nums, int target,int n,int& ans){
        // if(target == 0){
        //     ans++;
        // }
        if(n == 0 && target == 0){
            ans++;
            return;
        }
        if(n<=0){
            return;
        }
        
        solve(nums,target-nums[n-1],n-1,ans);
        solve(nums,target+nums[n-1],n-1,ans);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int ans = 0;
        int n = nums.size();
        solve(nums,target,n,ans);
        return ans;
    }
};