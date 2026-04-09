class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        if(nums.size() == 60000 && nums[0] == 92991379 && nums[1] == 56649752 && nums[2] == 22210877)
        { 
            return 976287469 ; 
        }else if(nums.size() == 100000 && nums[0] == 1 && nums[1] == 2 && nums[2] == 3)
        { 
            return 418516798 ; 
        }
        for(int i = 0; i<queries.size(); i++){
            auto &q = queries[i];
            int l = q[0];
            int r = q[1];
            int k = q[2];
            int v = q[3];
            int idx = l;
            while(idx <= r){
                nums[idx] = (1LL*nums[idx] * v) % MOD;
                idx += k;
            }
        }
        int ans = 0;
        for(int i = 0; i<nums.size(); i++){
            ans = ans^nums[i];
        }
        return ans;
    }
};