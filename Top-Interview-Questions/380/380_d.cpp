class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> map;
    vector<int> arr;

    RandomizedSet() {
        srand(time(0));
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (map.find(val) != map.end())
            return false;
        map.insert({val, arr.size()});
        arr.push_back(val);
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (map.find(val) == map.end())
            return false;
        int pos = map[val];
        swap(arr[pos], arr.back());//To delete in O(1) swap with last element since order doesn't matter
        map[arr[pos]] = pos;//Have to update the index in the hash-map.
        arr.pop_back();
        map.erase(val);
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */