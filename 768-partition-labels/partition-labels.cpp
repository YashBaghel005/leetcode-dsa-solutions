class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>> mp;
        for(int i = 0; i<s.size(); i++){
            if(mp.find(s[i])!=mp.end()){
                mp[s[i]].second = i;
            }else{
                mp[s[i]].first = i;
                mp[s[i]].second = i;
            }
        }
        vector<vector<int>> interval;
        for(auto &[key,value]:mp){
            interval.push_back({value.first,value.second});
        }
        sort(interval.begin(),interval.end());
        vector<int> ans;
        int si = interval[0][0];
        int ei = interval[0][1];
        // int len = ei-si+1;
        for(int j = 1; j<interval.size(); j++){
            int sj = interval[j][0];
            int ej = interval[j][1];
            if(ei > sj){
                ei = max(ei,ej);
                // len = ei-si+1;
            }else{
                ans.push_back(ei-si+1);
                // len = 1;
                si = sj;
                ei = ej;
            }
        }
        ans.push_back(ei-si+1);
        return ans;
    }
};