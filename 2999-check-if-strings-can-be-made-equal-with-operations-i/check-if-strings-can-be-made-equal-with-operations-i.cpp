class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        int n = s1.size();
        for(int i = 0; i<n; i++){
            int j = i+2;
            if(j >= n){
                break;
            }
            if(s1[i] == s2[i]){
                continue;
            }
            if(s1[i] == s2[j]){
                swap(s2[i],s2[j]);
            }
        }
        for(int i = 0; i<n; i++){
            if(s1[i] != s2[i]){
                return false;
            }
        }
        return true;
    }
};