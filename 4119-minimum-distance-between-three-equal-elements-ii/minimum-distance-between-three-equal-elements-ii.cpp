class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for(auto &[key,value] : mp){
            if(value.size() >= 3){
                for(int i = 0; i<value.size()-2; i++){
                    // cout<< abs(value[i]-value[i+1]) << ' '<<abs(value[i+2]-value[i+1]) <<' '<< abs(value[i+2]-value[i])<<endl;
                    int a = abs(value[i]-value[i+1]) + abs(value[i+2]-value[i+1]) + abs(value[i+2]-value[i]);
                    // cout<<a<<endl;
                    ans = min(ans,a);
                }
            }
        }
        if(ans == INT_MAX){
            return -1;
        }
        return ans;
    }
};