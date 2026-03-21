class Solution {
public:
    bool isPalindrome(string s) {
        // remove all non aphameric character 
        string n;
        for(int i = 0; i<s.size(); i++){
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9')){
                n.push_back(s[i]);
            }
        }
        // cout<<n<<endl;
        for(int i = 0; i<n.size(); i++){
            if(n[i]>='A' && n[i] <= 'Z'){
                n[i] = n[i]+32;
            }
        }
        // cout<<n<<endl;
        int i = 0;
        int j = n.size()-1;
        while(i<=j){
            if(n[i] != n[j]){
                // cout<<i<<' '<<j<<endl;
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};