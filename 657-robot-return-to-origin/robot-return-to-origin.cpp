class Solution {
public:
    bool judgeCircle(string s) {
        int count_u = 0; 
        int count_d = 0; 
        int count_l = 0; 
        int count_r = 0; 
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'U'){
                count_u++;
            }
            else if(s[i] == 'D'){
                count_d++;
            }
            else if(s[i] == 'R'){
                count_r++;
            }
            else if(s[i] == 'L'){
                count_l++;
            }
        }
        if(count_u == count_d && count_l == count_r){
            return true;
        }
        return false;
    }
};