class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i = 0; i<times.size(); i++){
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];

            mp[a].push_back({b,c});
        }
        vector<int> time(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int node = t.second;
            int cost = t.first;
            if(time[node] != INT_MAX){
                continue;
            }
            time[node] = cost;
            for(int i = 0; i<mp[node].size(); i++){
                int child = mp[node][i].first;
                int c_cost = mp[node][i].second;
                pq.push({cost+c_cost,child});
            }
        }
        int ans = INT_MIN;
        for(int i = 1; i<time.size(); i++){
            if(time[i] == INT_MAX){
                return -1;
            }
            ans = max(ans,time[i]);
        }
        return ans;
    }
};