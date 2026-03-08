class Solution {
public:
    void make_strings(int n,int i, vector<string> &ans,string output){
        if(i == n){
            ans.push_back(output);
            return;
        }
        output.push_back('0');
        make_strings(n,i+1,ans,output);
        output.pop_back();

        output.push_back('1');
        make_strings(n,i+1,ans,output);
        output.pop_back();
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        vector<string> ans;
        make_strings(n,0,ans,"");
        unordered_map<string,int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i = 0; i<ans.size(); i++){
            if(mp.find(ans[i]) == mp.end()){
                return ans[i];
            }
        }
        return "";
    }
};