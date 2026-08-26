class Solution {
public:
    string shortestBeautifulSubstring(string s, int p) {
        vector<string> ans;
        int len = INT_MAX;
        for(int i = 0; i<s.size(); i++){
            for(int j = i; j<s.size(); j++){
                int count = 0;
                for(int k = i; k<=j; k++){
                    if(s[k] == '1'){
                        count++;
                    }
                }
                if(count == p){
                    len = min(len,j-i+1);
                    string t = s.substr(i,j-i+1);
                    ans.push_back(t);
                }
            }
        }
        if(len == INT_MAX){
            return "";
        }
        set<string> st;
        for(int i = 0; i<ans.size(); i++){
            if(ans[i].size() == len){
                st.insert(ans[i]);
            }
        }
        for(string t:st){
            return t;
        }
        return "";
    }
};