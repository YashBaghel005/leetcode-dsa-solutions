class Solution {
public:
    // long long fact(int n){
    //     long long mul = 1;
    //     for(int i = 1; i<=n; i++){
    //         mul = 1LL*mul*i;
    //     }
    //     return mul;
    // }
    long long combination(int n,int r){
        if(r == 0 || r == n){
            return 1;
        }
        return combination(n,r-1)*(n-r+1)/r;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i = 0; i<numRows; i++){
            vector<int> p;
            for(int j = 0; j<=i; j++){
                p.push_back(combination(i,j));
            }
            ans.push_back(p);
        }
        return ans;
    }
};