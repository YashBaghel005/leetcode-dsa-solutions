class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0; int j = 0;

        int n =nums.size();
        // if(n == 1){
        //     return 0;
        // }
        int count = 0;
        while(j<nums.size()-1){
            int maxi = INT_MIN;
            for(int k = i; k<=j; k++){
                maxi = max(maxi,nums[k]+k);
            }
            count++;
            i = j+1;
            j = maxi;
        }
        return count;
    }
};