class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el = nums[0];
        int cnt = 0;
        for(int i = 0; i<nums.size(); i++){
            if(cnt == 0){
                el = nums[i];
            }
            if(nums[i] == el){
                cnt++;
            }else{
                cnt--;
            }
        }
        return el;
    }
};