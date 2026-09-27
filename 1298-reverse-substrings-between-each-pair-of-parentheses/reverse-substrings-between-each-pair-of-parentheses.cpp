class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> open;
        vector<int> close;
        stack<int> st;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            if(s[i] == ')'){
                close.push_back(i);
                int t = st.top();
                st.pop();
                open.push_back(t);
            }
        }
        // reverse(close.begin(),close.end());
        for(int i = 0; i<open.size(); i++){
            reverse(s.begin()+open[i],s.begin()+close[i]+1);
            cout<<s<<endl;
        }
        string ans = "";
        for(int i = 0; i<s.size(); i++){
            if(s[i] == '(' || s[i] == ')'){
                continue;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};