class Solution {
public:
    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> mp;
        int i = 0;
        int ans = 0;
        for(int j = 0; j<s.size() && j>=i; j++){
            mp[s[j]]++;
            char max_key = '.';
            int max_value = 0;
            for(auto &[key,value] : mp){
                if(max_value < value){
                    max_key = key;
                    max_value = value;
                }
            }
            if((j-i+1)-max_value <= k){
                ans = max(ans,j-i+1);
            }else{
                int maxi_value = max_value;
                while((j-i+1)-maxi_value > k){
                    mp[s[i]]--;
                    i++;
                    char maxi_key = '.';
                    maxi_value = 0;
                    for(auto &[key,value] : mp){
                        if(maxi_value < value){
                            maxi_key = key;
                            maxi_value = value;
                        }
                    }
                }
                ans = max(ans,j-i+1);
                
            }
        }
        return ans;
    }
};