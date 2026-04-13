class Solution {
public:
    unordered_map<string, bool> dp;
    bool solve(string s,vector<string>& wordDict,string t){
        if(s == t){
            return true;
        }if(s.size() < t.size()){
            return false;
        }
        if (dp.count(t)) return dp[t];
        bool ans = false;
        for(int i = 0; i<wordDict.size(); i++){
            string next = t + wordDict[i];
            if (s.substr(0, next.size()) != next) continue;
            ans = ans||solve(s,wordDict,t+wordDict[i]);
            if (ans) break; 
        }
        return dp[t] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        
        return solve(s,wordDict,"");
    }
};