class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keyToValues[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(keyToValues.find(key) == keyToValues.end())
            return "";
        
        auto it = keyToValues[key].upper_bound(timestamp);
        if(it == keyToValues[key].begin())
            return "";
        
        it--;
        return it->second;
    }
    
private:
    unordered_map<string, map<int, string>> keyToValues;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */