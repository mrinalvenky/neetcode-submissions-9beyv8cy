class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> hmap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hmap[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        if (!hmap.count(key)) return "";
        auto& lst = hmap[key];
        int l = 0, r = static_cast<int>(lst.size()) - 1;
        if (lst.front().first > timestamp) return "";
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (lst[mid].first <=  timestamp) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return lst[r].second;
    }
};
