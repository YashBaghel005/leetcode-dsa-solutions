class Solution {
public:
    unordered_map<string,bool> mp;
    bool solve(string s, vector<string>& wordDict,string t){
        if(s == t){
            return true;
        }if(s.size() < t.size()){
            return false;
        }
        if (mp.count(t)) return mp[t];
        bool ans = false;
        for(int i = 0; i<wordDict.size(); i++){
            string next = t+wordDict[i];
            if(s.substr(0,next.size()) != next) continue;
            ans = ans || solve(s,wordDict,t+wordDict[i]);
        }
        return mp[t] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        return solve(s,wordDict,"");
    }
};