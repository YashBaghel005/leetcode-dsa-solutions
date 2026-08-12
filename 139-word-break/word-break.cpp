class Solution {
public:
    bool pre_match(string &target,string &str){
        if(target.size() < str.size()){
            return false;
        }
        for(int i = 0; i<str.size(); i++){
            if(str[i] != target[i]){
                return false;
            }
        }
        return true;
    }
    bool solve(string target,vector<string>& wordDict,string str,unordered_map<string,bool> &dp){
        if(str.size() > target.size()){
            return false;
        }
        if(str == target){
            return true;
        }

        if(dp.find(str) != dp.end()){
            return dp[str];
        }

        bool ans = false;
        for(int i = 0;i<wordDict.size(); i++){
            if(pre_match(target,str))
                ans = ans || solve(target,wordDict,str+wordDict[i],dp);
            if(ans){
                return true;
            }
        }
        return dp[str] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,bool> dp;
        return solve(s,wordDict,"",dp);
    }
};