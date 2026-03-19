class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        // creatinf initial wwindow
        for(int i = 0; i<nums.size() && i<=k; i++){
            mp[nums[i]]++;
            if(mp[nums[i]] > 1){
                return true;
            }
        }
        int i = 0;
        int j = k+1;
        while(j<nums.size()){
            mp[nums[i]]--;
            i++;
            mp[nums[j]]++;
            if(mp[nums[j]] > 1){
                return true;
            }
            j++;
        }
        return false;
    }
};