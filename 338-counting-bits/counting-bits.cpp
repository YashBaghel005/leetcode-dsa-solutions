class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i<=n; i++){
            int num = i;
            int count = 0;
            while(num != 0){
                int rem = num%2;
                num = num/2;
                if(rem == 1){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};