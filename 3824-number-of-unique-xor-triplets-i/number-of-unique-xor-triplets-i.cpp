class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2){
            return n;
        }
        int i = 0;
        while(pow(2,i) < n){
            i++;
        }
        if(pow(2,i) == n){
            return pow(2,i+1);
        }
        return pow(2,i);
    }
};