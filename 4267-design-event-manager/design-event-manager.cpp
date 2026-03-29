class EventManager {
public:
    priority_queue<pair<int,int>> pq; // {priority, -eventId}
    unordered_map<int,int> mp;        // eventId -> current priority

    EventManager(vector<vector<int>>& events) {
        for (auto &e : events) {
            int id = e[0], pr = e[1];
            pq.push({pr, -id});
            mp[id] = pr;
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        mp[eventId] = newPriority;
        pq.push({newPriority, -eventId});
    }

    int pollHighest() {
        while (!pq.empty()) {
            auto [priority, negId] = pq.top();
            pq.pop();

            int id = -negId;

            // skip outdated entries
            if (mp[id] != priority) continue;

            mp.erase(id);
            return id;
        }
        return -1;
    }
};