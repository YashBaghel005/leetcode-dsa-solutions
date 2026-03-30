class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_index = nums[0];
        int n = nums.size();
        for(int i = 1; i<n; i++){
            if(max_index < i){
                return false;
            }
            max_index = max(max_index,i+nums[i]);
        }
        return true;
    }
};