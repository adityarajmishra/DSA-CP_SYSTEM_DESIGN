
class LRUCache {
private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> lruOrder;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // Move the key to the front of the lruOrder list
            lruOrder.erase(cache[key].second);
            lruOrder.push_front(key);

            // Update the iterator in the cache
            cache[key].second = lruOrder.begin();

            return cache[key].first;
        }

        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // Key already exists, update the value and move to the front
            lruOrder.erase(cache[key].second);
        } else if (cache.size() >= capacity) {
            // Remove the least recently used key
            int lruKey = lruOrder.back();
            cache.erase(lruKey);
            lruOrder.pop_back();
        }

        // Add the new key to the cache and lruOrder
        lruOrder.push_front(key);
        cache[key] = {value, lruOrder.begin()};
    }
};
