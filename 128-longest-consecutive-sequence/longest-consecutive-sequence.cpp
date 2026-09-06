class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        unordered_set<int> st;
        for(int x:nums){
            st.insert(x);
        }
        int ans = 1;
        for(int i = 0; i<nums.size(); i++){
            int x = nums[i]-1;
            if(st.find(x-1) == st.end()){
                int count = 0;
                while(st.find(x) != st.end()){
                    count++;
                    x++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};