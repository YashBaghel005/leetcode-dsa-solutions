class Solution {
public:
    int solve(string &s,int &p,int i, int j){
        if(i > j){
            return 0;
        }
        vector<char> nt;
        vector<int> freq(26,0);
        for(int k = i; k<=j; k++){
            freq[s[k]-'a']++;
        }
        for (int x = 0; x < 26; x++) {
            if (freq[x] < p) {
                nt.push_back('a' + x);
            }
        }
        int ans = 0;
        bool found = false;
        int k = i;
        for(k; k <= j; k++){
            if(find(nt.begin(),nt.end(),s[k]) != nt.end()){
                ans = max(ans,solve(s,p,i,k-1));
                found = true;
                i = k+1;
            }
        }
        if (found) {
            ans = max(ans, solve(s, p, i, j));
        } else {
            ans = j - i + 1;
        }
        return ans;
    }
    int longestSubstring(string s, int k) {
        return solve(s,k,0,s.size()-1);
    }
};