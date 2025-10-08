class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        map<int, unordered_set<int>> m;
        unordered_set<int> visitedStops;
        unordered_set<int> visitedBuses;
        queue<pair<int, int>>q; //current stop + how many hops
        int stop = source;
        int hops = 0;

        if(source == target){
            return 0;
        }

        for(int i = 0; i < routes.size(); i++){
            for (int stop1 : routes[i]) {
                m[stop1].insert(i);  // key = stop, value = bus index
            }
        }

        q.push({source, 1});

        while(!q.empty()){
            stop = q.front().first;
            hops = q.front().second;
            q.pop();

            for (int bus : m[stop]) {
                if (visitedBuses.count(bus)){
                    continue;
                }
                visitedBuses.insert(bus);
                for (int nextStop : routes[bus]) {
                    if (!visitedStops.count(nextStop)) {
                        if(nextStop == target){
                            return hops;
                        }
                        visitedStops.insert(nextStop);
                        q.push({nextStop, hops + 1});
                    }
                }
            }
        }

    return -1;
    }
};