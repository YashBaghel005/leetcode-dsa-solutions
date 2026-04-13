class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        vector<int> mp;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == target){
                mp.push_back(i);
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i<mp.size(); i++){
            ans = min(ans,abs(mp[i]-start));
        }
        return ans;
    }
};