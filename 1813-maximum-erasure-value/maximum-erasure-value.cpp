class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        while(j<nums.size()){
            mp[nums[j]]++;
            if(mp[nums[j]] > 1){
                while(mp[nums[j]] > 1){
                    mp[nums[i]]--;
                    sum -= nums[i];
                    i++;
                }
                sum+=nums[j];
            }else{
                sum+=nums[j];
            }
            ans = max(sum,ans);
            j++;
        }
        return ans;
    }
};