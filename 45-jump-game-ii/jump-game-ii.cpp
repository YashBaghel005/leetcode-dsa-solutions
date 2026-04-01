class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int ans = 0;
        int farthest = 0;
        while(j < nums.size()-1){
            for(int k = i; k<=j; k++){
                farthest = max(farthest,nums[k]+k);
            }
            i = j+1;
            j = farthest;
            ans++;
        }
        return ans;
    }
};