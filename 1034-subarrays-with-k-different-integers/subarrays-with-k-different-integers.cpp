class Solution {
public:

    int solve(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        int i = 0;
        int count = 0;
        for(int j = 0; j<nums.size();j++){
            mp[nums[j]]++;
            // bool flag = true;
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
                // flag = false;
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