class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size(); i++){
            int a = nums[i];
            int t = target-a;
            if(mp.find(t) != mp.end()){
                return {i,mp[t]};
            }
            mp[a] = i;
        }
        return {};
    }
};