class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        if(n == 1){
            if(nums[0] >= target)
                return 1;
            else
                return 0;
        }
        int i = 0;
        int j = 0;
        int sum = nums[i];
        int ans = INT_MAX;
        while(j<n){
            if(sum >= target){
                ans = min(ans,j-i+1);
                sum-=nums[i];
                i++;
            }
            else{
                j++;
                if(j<n){
                    sum+=nums[j];
                }
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }
};