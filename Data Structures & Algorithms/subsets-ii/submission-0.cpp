class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        std::vector<std::vector<int>> res{};
        std::vector<int> curr_set{};
        std::ranges::sort(nums);
        backtrace(nums, res, curr_set, 0);
        return res;
    }

    void backtrace(std::vector<int> const& nums, std::vector<std::vector<int>>& res, std::vector<int> curr_set, int index) {
        if (index == nums.size()) {
            res.push_back(curr_set);
            return;
        }
        curr_set.push_back(nums[index]);
        backtrace(nums, res, curr_set, index + 1);
        curr_set.pop_back();
        while(index + 1 < nums.size() && nums[index + 1] == nums[index]) {
            ++index;
        }
        backtrace(nums, res, curr_set, index + 1);
    }

};
