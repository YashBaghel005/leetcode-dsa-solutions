class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int h = 0;
        int ans = 0;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                h++;
            }else if(s[i] == ')'){
                st.pop();
                h--;
            }
            ans = max(ans,h);
        }
        return ans;
    }
};