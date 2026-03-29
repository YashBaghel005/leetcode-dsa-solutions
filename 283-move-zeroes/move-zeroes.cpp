class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        unordered_map<int,int> mp;
        int count_zeros = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                mp[i] = count_zeros;
            }else{
                count_zeros++;
            }
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] != 0){
                nums[i-mp[i]] = nums[i];
            }
        }
        int j = nums.size()-1;
        while(count_zeros!=0){
            nums[j] = 0;
            j--;
            count_zeros--;
        }
       
    }
};