class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> mp;
        for(int i = 0; i<flights.size(); i++){
            int a = flights[i][0];
            int b = flights[i][1];
            int c = flights[i][2];

            mp[a].push_back({b,c});
        }
        vector<int> min_stops(n, INT_MAX);
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,src,0});
        min_stops[src] = 0;
        while(!pq.empty()){
            auto [cost,node,stops] = pq.top();
            pq.pop();
            if(node == dst){
                return cost;
            }
            if(stops > k) continue;
            if (stops > min_stops[node]) continue;
            min_stops[node] = stops;
            
            for (int i = 0; i < mp[node].size(); i++) {
                pq.push({cost + mp[node][i].second, mp[node][i].first, stops + 1});
            }
        }
        return -1;
    }
};