class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum == k){
                ans++;
            }
            int target = sum-k;
            if(mp.find(target) != mp.end()){
                ans+=mp[target];
            }
            mp[sum]++;
        }
        return ans;
    }
};