class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::ranges::sort(nums);
        std::vector<std::vector<int>> res;
        for(int i{}; i < (nums.size() - 2); i++) {

            int num{nums[i]};

            // duplicate
            if (i > 0 && nums[i - 1] == num) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = num + nums[left] + nums[right];
                if(sum == 0) {
                    std::vector<int> triplets;
                    triplets.reserve(3);
                    triplets.emplace_back(num);
                    triplets.emplace_back(nums[left]);
                    triplets.emplace_back(nums[right]);
                    res.push_back(std::move(triplets));
                    left += 1;
                    right -= 1;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left += 1;
                    }
                } else if(sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
            
        }
        return res;
    }
};
