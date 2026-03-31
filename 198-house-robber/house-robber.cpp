class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        vector<int> dp = nums;
        dp.push_back(0);

        if(n == 1){
            return nums[0];
        }if(n == 2){
            return max(nums[0],nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = nums[1];
        int maxi = dp[0];

        for(int i = 2; i<=n; i++){

            dp[i] += maxi;
            dp[i] = max(dp[i],dp[i-1]);
            // cout<<dp[i]<<endl;
            maxi = max(maxi,dp[i-1]);
        }
        return dp[n];
    }
};