class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(int x:nums){
            st.insert(x);
        }
        int temp = k;
        while(true){
            if(st.find(k) == st.end()){
                break;
            }
            k = k+temp;
        }
        return k;
    }
};