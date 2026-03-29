class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }if(nums.size() == 1){
            return 1;
        }
        sort(nums.begin(),nums.end());
        int count = 1;
        int ans = 1;
        vector<int> a = nums;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i] == nums[i+1]){
                continue;
            }
            a.push_back(nums[i]);
        }
        a.push_back(nums[nums.size()-1]);
        for(int i = 0; i<a.size()-1; i++){
            if(a[i]+1 == a[i+1] ){
                count++;
            }else{
                count = 1;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};