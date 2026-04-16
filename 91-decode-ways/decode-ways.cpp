class Solution {
public:
    int solve(string s,int index,int n,vector<int> &dp){
        if(index == n ){
            return 1;
        }
        if(s[index] == '0'){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        // 1 lete hai
        int a = solve(s,index+1,n,dp);
        // 2 lete hai 
        int b = 0;
        if(index + 1 < n && (s[index] == '1' || (s[index] == '2' && s[index+1] <= '6'))){
            b = solve(s,index+2,n,dp);
        }
        return dp[index] = a+b;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return solve(s,0,n,dp);
    }
};