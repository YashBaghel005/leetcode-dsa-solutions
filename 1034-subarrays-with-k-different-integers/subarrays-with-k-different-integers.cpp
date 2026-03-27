class Solution {
public:
    int solve(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int count = 0;
        int i = 0;
        for(int j = 0; j<nums.size(); j++){
            mp[nums[j]]++;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(mp.size() <= k){
                count+=j-i+1;
            }
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int a = solve(nums,k);
        int b = solve(nums,k-1);
        return a-b;
    }
};