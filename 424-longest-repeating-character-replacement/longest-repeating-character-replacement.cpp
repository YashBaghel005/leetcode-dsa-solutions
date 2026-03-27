class Solution {
public:
    int characterReplacement(string s, int k) {
        if(k == 0){
            int a = 0;
            int b = 0;
            for(int i = 0; i<s.size()-1; i++){
                if(s[i] == s[i+1]){
                    a++;
                }else{
                    a = 0;
                }
                b = max(b,a);
            }
            return b+1;
        }
        unordered_map<char,int> mp;
        int i = 0;
        int ans = 0;
        int max_freq = 0;
        for(int j = 0; j<s.size(); j++){
            mp[s[j]]++;
            max_freq = max(max_freq,mp[s[j]]);
            while((j-i+1)-max_freq > k){
                mp[s[i]]--;
                i++;
            }
            ans = max(ans,j-i+1);
        }
        return ans;
    }
};