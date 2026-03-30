class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int> mp_even1;
        unordered_map<char,int> mp_odd1;
        unordered_map<char,int> mp_even2;
        unordered_map<char,int> mp_odd2;
        for(int i = 0; i<s1.size(); i++){
            if(i%2 == 0){
                mp_even1[s1[i]]++;
                mp_even2[s2[i]]++;
            }else{
                mp_odd1[s1[i]]++;
                mp_odd2[s2[i]]++;
            }
        }
        if(mp_even1 == mp_even2 && mp_odd1 == mp_odd2){
            return true;
        }
        return false;;
    }
};