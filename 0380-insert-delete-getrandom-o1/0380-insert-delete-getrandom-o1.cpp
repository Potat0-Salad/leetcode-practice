class RandomizedSet {
private:
    std::unordered_set<int> set;
public:

    RandomizedSet() {
        srand((unsigned) time(NULL));
    }
    
    bool insert(int val) {
        return set.insert(val).second;
    }
    
    bool remove(int val) {
        return set.erase(val);
    }
    
    int getRandom() {
        vector<int> vec(set.begin(), set.end());

        return vec[rand() % vec.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */