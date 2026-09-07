class Solution {
public:
    int distinctSubseqII(string s) {
        int ans = 0;
        vector<int> dp(26,0);
        int MOD = 1e9+7;
        for(char ch:s){
            ch = ch-'a';
            int add = (ans-dp[ch]+MOD)%MOD;
            dp[ch] = 1+ans;
            ans = (dp[ch]+add)%MOD;
        }
        return ans;
    }
};