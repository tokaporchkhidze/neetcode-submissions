class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hash;
        std::vector<int> vec(2, 0);
        for(int i{}; i < std::ssize(nums); i++) {
            int left{target - nums[i]};
            if(auto const it{hash.find(nums[i])}; it != hash.cend()) {
                vec[0] = it->second;
                vec[1] = i;
                break;
            }
            hash.emplace(left, i);
        }
        return vec;
    }
};
