class LRUCache {
private:
    int capacity;
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end())
            return -1;
        
        dll.splice(dll.begin(), dll, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);

        if(it != mp.end()) {
            it->second->second = value;
            dll.splice(dll.begin(), dll, it->second);
            return;
        }

        if(dll.size() == capacity) {
            auto lru = dll.back();
            mp.erase(lru.first);
            dll.pop_back();
        }

        dll.emplace_front(make_pair(key, value));
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */