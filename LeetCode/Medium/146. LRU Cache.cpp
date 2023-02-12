class LRUCache {
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> myMap;
    void refreshPosition(int key, int value)
    {
        cache.erase(myMap[key]);
        cache.push_front(make_pair(key, value));
        myMap[key] = cache.begin();
    } 
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(myMap.find(key) != myMap.end())
        {
            refreshPosition(key, (*myMap[key]).second);
            return (*myMap[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(myMap.find(key) != myMap.end())
        {
            refreshPosition(key, value);
        }
        else
        {
            cache.push_front(make_pair(key, value));
            myMap[key] = cache.begin();
            if(myMap.size() > capacity)
            {
                myMap.erase(cache.back().first);
                cache.pop_back();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
