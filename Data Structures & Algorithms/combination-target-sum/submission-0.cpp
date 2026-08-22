class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        std::vector<int> curr_set{};
        std::vector<std::vector<int>> res{};
        backtrace(nums, 0, curr_set, target, res);
        return res;
    }

    void backtrace(std::vector<int>& nums, int index, std::vector<int>& curr_set, int target,
                   std::vector<std::vector<int>>& res) {
        if (target == 0) {
            res.push_back(curr_set);
            return;
        }
        if (target < 0 || index >= nums.size()) {
            return;
        }

        curr_set.push_back(nums[index]);
        backtrace(nums, index, curr_set, target - nums[index], res);
        curr_set.pop_back();
        backtrace(nums, index + 1, curr_set, target, res);
    }
};
