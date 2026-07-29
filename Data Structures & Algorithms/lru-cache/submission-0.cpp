class LRUCache
{
public:
    explicit LRUCache(int const capacity) : capacity_(capacity) {}

    int get(int const key)
    {
        if (auto const it{key_map_.find(key)}; it != key_map_.end()) {
            cache_.splice(cache_.begin(), cache_, it->second);
            return it->second->second;
        }
        return -1;
    }

    void put(int const key, int const value)
    {
        if (auto const it{key_map_.find(key)}; it != key_map_.end()) {
            it->second->second = value;
            cache_.splice(cache_.begin(), cache_, it->second);
        }
        else {
            key_map_.emplace(key, cache_.insert(cache_.begin(), std::make_pair(key, value)));
            if (cache_.size() > capacity_) {
                auto [removed_key, _]{cache_.back()};
                key_map_.erase(removed_key);
                cache_.pop_back();
            }
        }
    }

private:
    using Cache = std::list<std::pair<int, int>>;
    using KeyMap = std::unordered_map<int, Cache::iterator>;
    size_t capacity_;
    Cache cache_;
    KeyMap key_map_;
};