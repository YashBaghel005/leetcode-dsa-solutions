class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int> freq_p(26,0);
        vector<int> freq_s(26,0);
        for(int i = 0; i<p.size(); i++){
            freq_p[p[i]-'a']++;
            freq_s[s[i]-'a']++;
        }
        vector<int> ans;
        if(freq_s == freq_p){
            ans.push_back(0);
        }
        int i = 0;
        for(int j = p.size(); j<s.size(); j++,i++){
            freq_s[s[i]-'a']--;
            freq_s[s[j]-'a']++;
            if(freq_s == freq_p){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};