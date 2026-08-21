class Solution {
   public:
    using Subsets = std::vector<std::vector<int>>;
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        Subsets result;
        std::vector<int> curr_set{};
        backtrack(nums, 0, curr_set, result);
        return result;
    }

    void backtrack(std::vector<int> const& nums, int index, std::vector<int>& curr_set,
                   Subsets& subsets) {
        if (index >= nums.size()) {
            subsets.push_back(curr_set);
            return;
        }
        curr_set.push_back(nums[index]);
        backtrack(nums, index + 1, curr_set, subsets);
        curr_set.pop_back();
        backtrack(nums, index + 1, curr_set, subsets);
    }
};
