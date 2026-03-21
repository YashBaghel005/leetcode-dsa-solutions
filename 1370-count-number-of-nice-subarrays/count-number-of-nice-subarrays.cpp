class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0;
        int count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                nums[i] = 0;
            }else{
                nums[i] = 1;
            }
            sum+=nums[i];
            mp[sum]++;
            if(sum == k){
                count++;
            }
            int target = sum-k;
            if(mp.find(target) != mp.end()){
                count += mp[target];
            }
        }
        return count;
        
    }
};