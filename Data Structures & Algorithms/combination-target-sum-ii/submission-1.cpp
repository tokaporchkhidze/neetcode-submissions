class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res{};
        std::vector<int> curr_set{};
        std::ranges::sort(candidates);
        backtrace(candidates, 0, target, curr_set, res);
        return res;
    }

    void backtrace(std::vector<int>& nums, int index, int target, std::vector<int>& curr_set, 
    std::vector<std::vector<int>>& res) {
        // success
        if(target == 0) {
            res.push_back(curr_set);
            return;
        }
        // fail
        if(target < 0 || index >= nums.size()) {
            return;
        }

        curr_set.push_back(nums[index]);
        backtrace(nums, index + 1, target - nums[index], curr_set, res);
        curr_set.pop_back();
        while(index + 1 < nums.size() && nums[index + 1] == nums[index]) {
            ++index;
        }
        backtrace(nums, index + 1, target, curr_set, res);
    }
};
