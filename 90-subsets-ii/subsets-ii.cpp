class Solution {
public:
    void solve(vector<int>& nums,vector<int> output, set<vector<int>> &ans,int i){
        if(i >= nums.size()){
            ans.insert(output);
            output.clear();
            return ;
        }
        // include
        output.push_back(nums[i]);
        solve(nums,output,ans,i+1);
        output.pop_back();

        //exclude
        solve(nums,output,ans,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> output;
        sort(nums.begin(), nums.end()); 
        solve(nums,output,ans,0);
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }
};