class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int a = nums.size()/2;
        int ans = 0;
        for(auto &[key,value]:mp){
            if(value > a){
                ans = key;
                return key;
            }
        }
        return ans;
    }
};