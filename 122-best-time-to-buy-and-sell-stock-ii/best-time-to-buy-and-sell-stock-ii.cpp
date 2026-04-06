class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        for(int i = 0; i<prices.size()-1; i++){
            int a = 0;
            if(prices[i] < prices[i+1]){
                a = prices[i+1]-prices[i];
            }
            ans+=a;
        }
        return ans;
    }
};