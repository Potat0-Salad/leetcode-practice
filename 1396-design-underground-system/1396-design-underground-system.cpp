class UndergroundSystem {
    map<pair<string,string>, vector<int>> times; //list of times travelling from a to b
    unordered_map<int, pair<string, int>> travelling; //id, check-in station, checked-in time

public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        travelling[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string stationIn = travelling[id].first;
        int totalTime = t - travelling[id].second;

        travelling.erase(id);

        times[{stationIn, stationName}].push_back(totalTime);

    }
    
    double getAverageTime(string startStation, string endStation) {
        vector<int> all = times[{startStation, endStation}];
        double totalTime = 0;
        double totalTrips = 0;

        for(int i = 0; i < all.size(); i++){
            totalTime += all[i];
            totalTrips++;
        }

        return totalTime / totalTrips;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */