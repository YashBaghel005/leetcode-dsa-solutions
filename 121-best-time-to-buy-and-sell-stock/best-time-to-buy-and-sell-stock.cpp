class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> mp(n,0);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            if(st.empty()){
                mp[i] = prices[i];
            }else if(st.top()>=prices[i])
                mp[i] = st.top();
            // else
            //     // st.push(prices[])
            if(st.empty() || prices[i] > st.top()){
                st.push(prices[i]);
            }
        } 
        int ans = INT_MIN;
        for(int i = 0; i<n; i++){
            ans = max(ans,mp[i]-prices[i]);
        }
        return ans;
    }
};