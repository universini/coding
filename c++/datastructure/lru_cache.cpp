/*
    In this implementation, the LRU cache is represented using an unordered map (cache)
    to store key-value pairs, where the key is an integer and the value is a pair
    consisting of the actual value and an iterator pointing to the key's position in a
    doubly linked list (lruList). The list keeps track of the most recently used keys,
    with the most recently used key at the front and the least recently used key at the back.

    The get() function checks if the key exists in the cache. If found, it moves the key to
    the front of the list and returns the associated value. Otherwise, it returns -1 to
    indicate a cache miss.

    The put() function inserts or updates a key-value pair in the cache. If the key already
    exists, it updates the value and moves the key to the front of the list.
    If the cache is full, it
*/

#include <iostream>
#include <list>
#include <unordered_map>

using lru_cache_t = std::unordered_map<int, std::pair<int, std::list<int>::iterator>>;
using lru_list_t = std::list<int>;

class lru_cache
{
    public:
        lru_cache(int num_entries) : m_num_cache_entries(num_entries){}

        int cache_get(int key);
        void cache_put(int key, int value);

    private:
        unsigned int m_num_cache_entries;
        lru_cache_t m_lru_cache;
        lru_list_t m_lru_list;
};

int lru_cache::cache_get(int key)
{
    std::pair<int, std::list<int>::iterator> cache_entry;
    int old_val;

    if (m_lru_cache.find(key) == m_lru_cache.end())
    {
        return -1;
    }

    // insert recently accessed entry into front of the list
    cache_entry = m_lru_cache[key];
    old_val = cache_entry.first;
    m_lru_list.erase(cache_entry.second);
    m_lru_list.push_front(old_val);
    cache_entry.second = m_lru_list.begin();

    return old_val;
}

void lru_cache::cache_put(int key, int new_val)
{
    std::pair<int, std::list<int>::iterator> cache_entry;
    int old_val;

    // check if key exists
    if (m_lru_cache.find(key) != m_lru_cache.end())
    {
        // update an existing entry in cache
        cache_entry = m_lru_cache[key];
        m_lru_list.erase(cache_entry.second);
        m_lru_list.push_front(new_val);
        cache_entry.first = new_val;
        cache_entry.second = m_lru_list.begin();
    }

    if (m_lru_cache.size() >= m_num_cache_entries)
    {
        // remove least used entry from cache
        m_lru_cache.erase(m_lru_list.back());
        m_lru_list.pop_back();
    }

    // insert a new entry into cache
    m_lru_list.push_front(key);
    m_lru_cache[key] = std::make_pair(new_val, m_lru_list.begin());
}

int main (void)
{
    lru_cache cache_inst(2);

    cache_inst.cache_put(1, 1);
    cache_inst.cache_put(2, 2);

    std::cout << cache_inst.cache_get(1) << std::endl;

    cache_inst.cache_put(3, 3);

    std::cout << cache_inst.cache_get(2) << std::endl;
    std::cout << cache_inst.cache_get(3) << std::endl;

    cache_inst.cache_put(4, 4);

    std::cout << cache_inst.cache_get(1) << std::endl;
    std::cout << cache_inst.cache_get(3) << std::endl;
    std::cout << cache_inst.cache_get(4) << std::endl;

    return 0;
}
