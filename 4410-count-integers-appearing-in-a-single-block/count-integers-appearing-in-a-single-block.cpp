class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, tuple<int, int, int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = {i, i, 1};
            } else {
                get<1>(mp[nums[i]]) = i;
                get<2>(mp[nums[i]]) += 1;
            }
        }

        int ans = 0;

        for (auto &[key, value] : mp) {
            if (get<2>(value) == get<1>(value) - get<0>(value) + 1) {
                ans++;
            }
        }

        return ans;
    }
};