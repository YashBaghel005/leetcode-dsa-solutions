class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int time = 0;
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i = 0; i<times.size(); i++){
            int a = times[i][0];
            int b = times[i][1];
            int c = times[i][2];
            mp[a].push_back({b,c});
        }
        vector<bool> vis(n+1,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto t = pq.top();
            pq.pop();
            int w = t.first;
            int node = t.second;
            if(vis[node]){
                continue;
            }
            vis[node] = true;
            time = max(time,w);
            for(int i = 0; i<mp[node].size(); i++){
                int child = mp[node][i].first;
                int child_wt = mp[node][i].second;
                if(!vis[child]){
                    pq.push({w+child_wt,child});
                }
            }
        }
        for(int i = 1; i<=n; i++){
            if(!vis[i]){
                return -1;
            }
        }
        return time;
    }
};