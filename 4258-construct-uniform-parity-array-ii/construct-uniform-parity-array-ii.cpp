class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int odd_count = 0;
        int even_count = 0;
        int min_even = INT_MAX;
        int min_odd = INT_MAX;
        for(int x:nums1){
            if(x%2 != 0){
                odd_count++;
                min_odd = min(min_odd,x);
            }else{
                even_count++;
                min_even = min(min_even,x);
            }
        }
        if (odd_count && even_count) {
            if(min_even < min_odd){
                return false;
            }
        }
        return true;
    }
};