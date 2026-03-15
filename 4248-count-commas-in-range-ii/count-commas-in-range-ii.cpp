class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000){
            return 0;
        }
        if(n<1000000){
            return n-1000+1;
        }
        long long ans = 0;
       ans += (1000000LL-1000)*1;
        if(n<1000000000){
            return ans+(n-1000000+1)*2;
        }
        ans+=(1000000000LL-1000000LL)*2;
        if(n<1000000000000){
            return ans+(n-1000000000+1)*3;
        }
        ans += (1000000000000LL-1000000000LL)*3;
        if(n<1000000000000000LL){
            return ans+(n-1000000000000+1)*4;
        }
        ans+=(1000000000000000LL-1000000000000LL)*4;
        return ans+(n-1000000000000000LL+1)*5;
    }
};