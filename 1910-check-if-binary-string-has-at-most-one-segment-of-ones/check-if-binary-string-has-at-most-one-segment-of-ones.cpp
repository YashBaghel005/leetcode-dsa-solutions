class Solution {
public:
    bool checkOnesSegment(string s) {
    
        int count  = 0;
        // count the number of changes 
        for(int i = 0; i<s.size()-1; i++){
            if(s[i] != s[i+1]){
                count++;
            }
        }
        if(count <= 1){
            return true;
        }
        if(count == 2 &&(s[0] == '0' )){
            return true;
        }
        return false;
    }
};