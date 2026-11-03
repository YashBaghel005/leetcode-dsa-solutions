class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int maxi = 1;
        for(int i = 0; i<nums.size(); i++){
            maxi = max(maxi,nums[i]);
        }
        for(int i = 0; i<nums.size(); i++){
            ans+=maxi-nums[i];
        }
        return ans;
    }
};