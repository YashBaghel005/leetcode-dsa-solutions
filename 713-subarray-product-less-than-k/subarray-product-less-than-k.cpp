class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int prod = 1;
        if(k == 0){
            return 0;
        }
        int count = 0;
        int i = 0;
        for(i; i<nums.size(); i++){
            if(nums[i] < k){
                break;
            }
        }
        for(int j = i; j<nums.size(); j++){
            prod = prod*nums[j];

            while(prod >= k){
                prod = prod/nums[i];
                i++;
            }

            count += j-i+1;
        }
        return count;
    }
};