class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            int target = sum - goal;
            if(sum == goal){
                count++;
            }
            if(mp.find(target) != mp.end()){
                count+=mp[target];
            }
            mp[sum]++;
        }
        return count;
    }
};