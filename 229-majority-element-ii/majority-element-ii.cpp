class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int el1 = INT_MIN;
        int vote1 = 0;
        int el2 = INT_MIN;
        int vote2 = 0;

        for(int i = 0; i<nums.size(); i++){
            if(vote1 == 0 && nums[i] != el2){
                vote1 = 0;
                el1 = nums[i];
            }
            else if(vote2 == 0 && nums[i] != el1){
                vote2 = 0;
                el2 = nums[i];
            }
            if(nums[i] == el1){
                vote1++;
            }else if(nums[i] == el2){
                vote2++;
            }else{
                vote1--;
                vote2--;
            }
        }
        vector<int> ans;
        int n = (int)(nums.size()/3) + 1;
        int count1 = 0;
        int count2 = 0;

        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == el1){
                count1++;
            }if(nums[i] == el2){
                count2++;
            }
        }
        if(count1 >= n){
            ans.push_back(el1);
        }
        if(count2 >= n){
            ans.push_back(el2);
        }
        return ans;
    }
};