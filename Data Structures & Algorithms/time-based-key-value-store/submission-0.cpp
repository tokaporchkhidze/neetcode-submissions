class TimeMap
{
public:
  void set(std::string key, std::string value, int timestamp)
  {
    map_.try_emplace(std::move(key))
            .first->second.insert({std::move(value), timestamp});
  }

  std::string get(std::string key, int timestamp)
  {
    if (auto const it{map_.find(key)}; it != map_.end()) {
      auto const &values{it->second};
      if (auto const target_it{values.upper_bound({"", timestamp})};
          target_it != values.begin())
      {
        return std::prev(target_it)->first;
      }
    }
    return "";
  }

private:
  using Value = std::pair<std::string, int>;

  struct CompareValue
  {
    bool operator()(Value const &lhs, Value const &rhs) const
    {
      return lhs.second < rhs.second;
    }
  };

  using KeyValueMap =
          std::unordered_map<std::string, std::set<Value, CompareValue>>;

  KeyValueMap map_{};
};