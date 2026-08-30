class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;
        for(int i = 0; i<nums.size(); i++){
            int size = nums[i];
            string s;
            while(size){
                int b = log2(size);
                if(b >= 25){
                    s.push_back('z');
                    size -= (1LL << 25);
                }
                else{
                    s.push_back('a' + b);
                    size -= (1LL << b);
                }
            }
            ans.push_back(s);
        }
        return ans;
    }
};