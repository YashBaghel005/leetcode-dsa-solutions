class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = -1;
        int vote1 = 0;
        int el2 = -1;
        int vote2 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(vote1 == 0 && nums[i] != el2){
                el1 = nums[i];
                vote1 = 0;
            }else if(vote2 == 0 && nums[i] != el1){
                el2 = nums[i];
                vote2 = 0;
            }
            if(el1 == nums[i]){
                vote1++;
            }else if(el2 == nums[i]){
                vote2++;
            }else{
                vote1--;
                vote2--;
            }
        }
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == el1){
                count1++;
            }else if(nums[i] == el2){
                count2++;
            }
        }
        vector<int> ans;
        if(count1 > nums.size()/3){
            ans.push_back(el1);
        }
        if(count2 > nums.size()/3){
            ans.push_back(el2);
        }
        return ans;
    }
};