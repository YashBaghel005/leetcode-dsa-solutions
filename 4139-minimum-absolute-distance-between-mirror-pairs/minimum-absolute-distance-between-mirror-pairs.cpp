class Solution {
public:
    int reverse(int n){
        int sum = 0;
        while(n!=0){
            int rem = n%10;
            sum=sum*10+rem;
            n = n/10;
        }
        return sum;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size(); i++){
            if(mp.find(nums[i]) != mp.end()){
                ans = min(ans,abs(i-mp[nums[i]]));
            }
            int rev = reverse(nums[i]);
            mp[rev] = i;
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};