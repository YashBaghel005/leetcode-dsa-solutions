class Solution {
public:
    int solve(string &word,int x1,int y1,int x2,int y2,int index,unordered_map<char,pair<int,int>>& mp,unordered_map<string,int>& dp){
        if(index >= word.size()){
            return 0;
        }
        string key = to_string(index)+","+to_string(x1)+","+to_string(y1)+","+to_string(x2)+","+to_string(y2);
        if(dp.count(key)) return dp[key]; 
        int cost = 0;
        int f1_cost = 0;
        int f2_cost = 0;
        if(x1 != -1 && y1 != -1){
            f1_cost = abs(mp[word[index]].first-x1)+abs(mp[word[index]].second-y1);
        }
        if(x2 != -1 && y2 != -1){
            f2_cost = abs(mp[word[index]].first-x2)+abs(mp[word[index]].second-y2);
        }
        
        cost += min(f1_cost+solve(word,mp[word[index]].first,mp[word[index]].second,x2,y2,index+1,mp,dp),f2_cost+solve(word,x1,y1,mp[word[index]].first,mp[word[index]].second,index+1,mp,dp));
        
        return dp[key] = cost;
        
    }
    int minimumDistance(string word) {
        unordered_map<char,pair<int,int>> mp;
        for(int i = 0; i<26; i++){
            mp['A'+i] = {i/6,i%6};
        }
        unordered_map<string,int> dp;
        return solve(word,-1,-1,-1,-1,0,mp,dp);
    }
};