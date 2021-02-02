class LRUCache {
public:
    unordered_map<int, list<pair<int, int>>::iterator> map;
    int filled, max_cap;
    list<pair<int, int>> list;
    std::list<pair<int, int>>:: iterator head;
    
    LRUCache(int capacity) {
        map.clear();
        while(!list.empty())
            list.pop_back();
        max_cap = capacity;
        filled = 0;
        head = list.begin();
    }
    
    int get(int key) {
        if(map.find(key) == map.end())
            return -1;
        else//if found we need to bring it to front
        {
            std::list<pair<int, int>>::iterator it = map[key];
            pair<int, int> temp = *it;
            list.erase(it);
            list.push_front(temp);
            head = list.begin();
            map[key] = head;
            return temp.second;
        }
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end())//This means we only need to update the value
        {
            list.erase(map[key]);
            list.push_front({key, value});
            head = list.begin();
            map[key] = head;
        }
        else //This means we need to add a new key
        {
            if(filled < max_cap)//If we still have more space so no need to remove anything
            {
                list.push_front({key, value});
                filled++;
                head = list.begin();
                map.insert({key, head});
            }
            else//First delete LRU then insert new pair.
            {
                map.erase(list.back().first);
                list.pop_back();
                list.push_front({key, value});
                head = list.begin();
                map.insert({key, head});
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