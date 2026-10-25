class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::vector<std::vector<std::string>> group_anagrams;
        std::map<std::array<int, 26>, std::vector<std::string>> hash;
        for(auto& str: strs) {
            std::array<int, 26> char_count{};
            for(auto& c: str) {
                char_count[static_cast<int>(c) - static_cast<int>('a')]++;
            }
            hash[char_count].emplace_back(str);
        }
        for(auto& [key, val]: hash) {
            group_anagrams.push_back(std::move(val));
        }
        return group_anagrams;
    }
};
