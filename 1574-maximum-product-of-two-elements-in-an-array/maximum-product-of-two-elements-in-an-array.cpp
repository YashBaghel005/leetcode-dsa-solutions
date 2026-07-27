class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0;
        int max2 = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[max1] < nums[i]){
                max1 = i;
            }
        }
        if(max1 == 0){
            max2 = 1;
        }
        for(int i = 0; i<nums.size(); i++){
            if(nums[max2] < nums[i] && i != max1){
                max2 = i;
            }
        }
        cout<<nums[max1]<<' '<<nums[max2];
        return (nums[max1]-1)*(nums[max2]-1);
    }
};