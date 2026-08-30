class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        // Try removing every element, and also try removing nothing
        for (int remove = -1; remove < n; remove++) {

            vector<int> arr;

            // Make array after removing nums[remove]
            for (int i = 0; i < n; i++) {
                if (i != remove) {
                    arr.push_back(nums[i]);
                }
            }

            int m = arr.size();

            if (m < 2)
                continue;

            vector<int> pref(m);
            vector<int> suff(m);

            // Prefix GCD
            pref[0] = arr[0];

            for (int i = 1; i < m; i++) {
                pref[i] = gcd(pref[i - 1], arr[i]);
            }

            // Suffix GCD
            suff[m - 1] = arr[m - 1];

            for (int i = m - 2; i >= 0; i--) {
                suff[i] = gcd(arr[i], suff[i + 1]);
            }

            int count = 0;

            // Check every split
            for (int i = 0; i < m - 1; i++) {

                // [0 ... i] | [i+1 ... m-1]
                if (pref[i] == suff[i + 1]) {
                    count++;
                }
            }

            ans = max(ans, count);
        }

        return ans;
    }
};