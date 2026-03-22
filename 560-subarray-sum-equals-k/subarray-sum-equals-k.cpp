class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1){
            if(nums[0] == k){
                return true;
            }else{
                return false;
            }
        }
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            sum+=nums[i];
            if(sum == k){
                count++;
            }
            int target = sum-k;
            if(mp.find(target) != mp.end()){
                count+=mp[target];
            }
            mp[sum]++;
        }
        return count;
    }
};