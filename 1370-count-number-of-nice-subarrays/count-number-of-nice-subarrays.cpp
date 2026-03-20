class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if(nums[0]%2 != 0){
            nums[0] = 1;
        }else{
            nums[0] = 0;
        }
        int count = 0;
        unordered_map<int,int> mp;
        mp[nums[0]]++;
        if(nums[0] == k){
            count++;
        }
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]%2 == 0){
                nums[i] = nums[i-1];
            }else{
                nums[i] = nums[i-1]+1;
            }
            mp[nums[i]]++;
            if(nums[i] == k){
                count++;
            }
            int target = nums[i]-k;
            if(mp.find(target) != mp.end()){
                count+=mp[target];
            }
        }
        return count;
    }
};