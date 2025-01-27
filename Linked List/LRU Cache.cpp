/*
https://leetcode.com/problems/lru-cache/
*/

class LRUCache {
public:
    std::list<std::pair<int, int>> cache;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> umap;
    int max;
    LRUCache(int capacity) {
        max = capacity;
    }
    
    int get(int key) {
        // If key is present. 
        if(umap.find(key) != umap.end()) {
            auto it = umap[key];
            cache.splice(cache.begin(), cache, it);
            return it->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // If key is already present.
        if(umap.find(key) != umap.end()) {
            auto it = umap[key];
            it->second = value;
            cache.splice(cache.begin(), cache, it);
            return;
        }
        
        // If key is not present and cache is full, remove the least used element.
        if(max <= cache.size()) {
            umap.erase(cache.back().first);
            cache.pop_back();
        }

        cache.push_front(make_pair(key, value));
        umap[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
