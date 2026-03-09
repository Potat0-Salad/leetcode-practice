class LRUCache{
    private:
    unordered_map<int, list<pair<int,int>>::iterator> cache;
    list<pair<int,int>> data;
    int totalSize;

    public:
    LRUCache(int capacity){
        cache.reserve(capacity);
        totalSize = capacity;
    }

    int get(int key){
        if(cache.contains(key)){
            data.splice(data.begin(), data, cache[key]);
            return data.front().second;
        }
        return -1;
    }

    void put(int key, int value){
        if(!cache.contains(key)){
            data.push_front({key, value});
            cache[key] = data.begin();
            if(cache.size() > totalSize){
                int oldKey = data.back().first;
                data.pop_back();
                cache.erase(oldKey);
            }
        }
        else{
            data.splice(data.begin(), data, cache[key]);
            data.front().second = value;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */