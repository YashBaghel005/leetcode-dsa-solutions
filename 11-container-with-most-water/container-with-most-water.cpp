class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int ans = INT_MIN;
        while(i<j){
            int s = height[i];
            int e = height[j];
            int water = min(height[i],height[j])*(j-i);
            ans = max(ans,water);
            if(s<e){
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};