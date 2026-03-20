class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char,int> s_mp;
        unordered_map<char,int> t_mp;
        for(int i = 0; i<s.size(); i++){
            s_mp[s[i]]++;
            t_mp[t[i]]++;
        }

        for(int i = 0; i<s.size(); i++){
            if(s_mp[s[i]] != t_mp[s[i]]){
                return false;
            }
        }

        return true;
    }
};