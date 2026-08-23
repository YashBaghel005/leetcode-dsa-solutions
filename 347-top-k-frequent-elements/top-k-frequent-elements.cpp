class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int x:nums){
            mp[x]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto &[key,value]:mp){
            if(pq.size() < k){
                pq.push({value,key});
            }else{
                auto t = pq.top();
                if(t.first < value){
                    pq.pop();
                    pq.push({value,key});
                }
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            ans.push_back(t.second);
        }
        return ans;
    }
};