class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n%2 != 0){
            return false;
        }
        stack<char> st;
        for(int i = 0; i<n; i++){
            if(s[i] == '(' ||s[i] == '{' ||s[i] == '['){
                st.push(s[i]);
            }else{
                char a;
                if(s[i] == ')'){
                    a = '(';
                }else if(s[i] == '}'){
                    a = '{';
                }else{
                    a = '[';
                }

                if(st.empty()){
                    return false;
                }
                char c = st.top();
                st.pop();
                if(a != c){
                    return false;
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};