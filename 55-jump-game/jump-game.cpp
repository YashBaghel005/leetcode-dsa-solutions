class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return true;
        }
        int max_index = 0;
        for(int i = 0; i<nums.size(); i++){
            max_index = max(max_index,i+nums[i]);
            if(i == n-1){
                return true;
            }
            if(i >= max_index){
                return false;
            }
        }
        return true;
    }
};