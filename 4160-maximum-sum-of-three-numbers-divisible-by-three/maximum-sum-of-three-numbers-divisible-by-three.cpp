class Solution {
public:
    int maximumSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i] % 3].push_back(nums[i]);
        }
        int sum = 0;
        vector<int> a = mp[0];
        vector<int> b = mp[1];
        vector<int> c = mp[2];
        int sum1 = 0;
        if (a.size() >= 3) {

           
            sum = max(sum, a[a.size() - 1] + a[a.size() - 2] +a[a.size() - 3]);
        }
        if (b.size() >= 3) {

            
            sum = max(sum, b[b.size() - 1] + b[b.size() - 2] + b[b.size() - 3]);
        }
        if (c.size() >= 3) {

            
            sum = max(sum, c[c.size() - 1] + c[c.size() - 2] + c[c.size() - 3]);
        }
        int count  = 0;
        if (a.size() >=1  && b.size() >=1 && c.size() >= 1){
            sum = max(sum, a[a.size() - 1] + b[b.size() - 1] + c[c.size() - 1]);
        }

        

        return sum;
    }
};