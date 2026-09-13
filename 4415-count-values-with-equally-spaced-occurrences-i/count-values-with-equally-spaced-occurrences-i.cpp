class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int ans = 0;
        for(auto &[key,value]:mp){
            if(value.size() == 3){
                if(value[1]-value[0] == value[2]-value[1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};