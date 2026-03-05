class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        string a1 = "";
        string a2 = "";
        int a = 0;
        for(int i = 0; i<n; i++){
            a1.push_back(a+'0');
            if(a == 0){
                a = 1;
            }else{
                a = 0;
            }
            a2.push_back(a+'0');
        }
        // cout<<a1<<endl;
        // cout<<a2<<endl;
        // number of mismatch with a1
        int miss_a1 = 0;
        int miss_a2 = 0;
    
        for(int i = 0; i<n; i++){
            if(s[i] != a1[i]){
                miss_a1++;
            }
            if(s[i] != a2[i]){
                miss_a2++;
            }
        }
        return min(miss_a1,miss_a2);
    }
};