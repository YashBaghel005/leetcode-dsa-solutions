class Solution {
public:
    int solve(string &s,string &t,int idx1,int idx2,vector<vector<int>> &dp){
        if(idx2 == t.size()){
            return 1;
        }else if(idx1 >= s.size() || idx2 >= t.size()){
            return 0;
        }
        if(dp[idx1][idx2] != -1){
            return dp[idx1][idx2];
        }
        int a = 0;
        int b = solve(s,t,idx1+1,idx2,dp);
        if(s[idx1] == t[idx2]){
            a = solve(s,t,idx1+1,idx2+1,dp);
        }
        return dp[idx1][idx2] = a+b;
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));
        return solve(s,t,0,0,dp);
    }
};