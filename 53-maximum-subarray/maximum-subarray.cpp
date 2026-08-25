class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        int ans = INT_MIN;
        for(int j = 0; j<nums.size(); j++){
            sum+=nums[j];
            if(sum < 0){
                sum = 0;
            }
            maxi = max(maxi,nums[j]);
            ans = max(ans,sum);
        }
        if(maxi < 0){
            return maxi;
        }
        return ans;
    }
};