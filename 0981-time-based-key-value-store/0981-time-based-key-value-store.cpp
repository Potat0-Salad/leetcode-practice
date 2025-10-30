class TimeMap {
public:
    unordered_map<string,vector<pair<string, int>>> data;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto it = data.find(key);
        if(it != data.end()){
            auto &vec = it->second;
            for(int i = vec.size() - 1; i >= 0; i--){
                if(vec[i].second <= timestamp){
                    return vec[i].first;
                }
            }
            return "";
        }
        else{
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */