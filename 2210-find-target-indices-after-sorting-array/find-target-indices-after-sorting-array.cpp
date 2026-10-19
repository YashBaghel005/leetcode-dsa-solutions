class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller = 0;
        int count  = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < target){
                smaller++;
            }else if(nums[i] == target){
                count++;
            }
        }
        vector<int> ans(count,0);
        for(int i = 0; i<ans.size(); i++){
            ans[i] = smaller;
            smaller++;
        }
        return ans;
    }
};