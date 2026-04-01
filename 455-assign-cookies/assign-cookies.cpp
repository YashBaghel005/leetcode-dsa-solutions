class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ans = 0;
        int i = 0;
        int j = 0;
        for(; i<g.size(); i++){
            for(;j<s.size(); j++){
                if(s[j]>=g[i]){
                    ans++;
                    j++;
                    break;
                }
            }
        }
        return ans;
    }
};