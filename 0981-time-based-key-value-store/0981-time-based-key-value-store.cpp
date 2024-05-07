class TimeMap {
private:
    unordered_map<string,vector<pair<string, int>>> timemap;
        
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if(timemap.find(key) == timemap.end())
            return "";
        int low = 0;
        int high = timemap[key].size()-1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(timemap[key][mid].second < timestamp)
                low = mid+1;
            else if(timemap[key][mid].second > timestamp)
                high = mid-1;
            else
                return timemap[key][mid].first;
        }
        if(high >= 0)
            return timemap[key][high].first;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */