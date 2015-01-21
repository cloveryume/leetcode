#include <list>
#include <unordered_map>
#include <iostream>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity);

    int get(int key);
    void set(int key, int value);
    void dump();

private:
    struct Elem {
        int key;
        int value;
        Elem(int _key, int _value) : key(_key), value(_value) { }
    };

    typedef list<Elem>::iterator elem_iterator;

    typedef unordered_map<int, elem_iterator> hash_map_t;
    typedef hash_map_t::iterator hash_iterator;
    typedef hash_map_t::value_type hash_value_type;

private:
    inline void append(int key, int value);
    inline void remove(elem_iterator it);

private:
    int capacity_;
    list<Elem> lst_;
    hash_map_t hash_map_;
};

LRUCache::LRUCache(int capacity) : capacity_(capacity) {
}

int LRUCache::get(int key) {
    hash_iterator hash_iter = hash_map_.find(key);
    if (hash_iter == hash_map_.end()) return -1;
    int value = hash_iter->second->value;
    remove(hash_iter->second);
    append(key, value);
    return value;
}

void LRUCache::set(int key, int value) {
    hash_iterator hash_iter = hash_map_.find(key);
    if (hash_iter != hash_map_.end()) {
        remove(hash_iter->second);                                                                                                                                                          
        append(key, value);
        return;
    }

    append(key, value);
    while (lst_.size() > capacity_) {
        remove(--lst_.end());
    }
}

void LRUCache::append(int key, int value) {
    lst_.emplace_front(key, value);
    pair<hash_iterator, bool> ret = 
        hash_map_.insert(hash_value_type(key, lst_.begin()));
    if (!ret.second) ret.first->second = lst_.begin();
}

void LRUCache::remove(elem_iterator it) {
    hash_map_.erase(it->key); 
    lst_.erase(it);
}

void LRUCache::dump() {
    for (elem_iterator it = lst_.begin(); it != lst_.end(); ++it) {
        cout << it->key << ":" << it->value << endl;
    }
}

int main(int argc, char *argv[])
{
    LRUCache c(2);
    c.set(2, 1);
    c.set(1, 1);
    c.set(2, 3);
    c.set(4, 1);

    c.dump();
    std::cout << c.get(1) << std::endl;
    
    return 0;
}
