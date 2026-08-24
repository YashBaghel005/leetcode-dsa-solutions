class Solution {
public:
    void increase_window(int n,unordered_map<int,int>& mp){
        for(int i = 2; i*i<=n; i++){
            if(n%i == 0){
                mp[i]++;
            
                while(n%i == 0)
                    n = n/i;
            }
        }
        if(n > 1){
            mp[n]++;
        }
    }
    void shrink_window(int n,unordered_map<int,int>& mp){
        for(int i = 2; i*i<=n; i++){
            if(n%i == 0){
                mp[i]--;
                if(mp[i] == 0){
                    mp.erase(i);
                }
            
                while(n%i == 0)
                    n = n/i;
            }
        }
        if(n > 1){
            mp[n]--;
            if(mp[n] == 0){
                mp.erase(n);
            }
        }
    }
    int longestSubarray(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        int i = 0;
        for(int j = 0; j<nums.size(); j++){
            increase_window(nums[j],mp);

            while(mp.size()>k){
                shrink_window(nums[i],mp);
                i++;
            }

            ans = max(ans,j-i+1);
        }
        return ans;
    }
};