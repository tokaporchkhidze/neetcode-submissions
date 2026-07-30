class Solution {
public:
    int missingNumber(vector<int>& nums) {
        std::ranges::sort(nums);
        for(auto i{0}; i < std::ssize(nums); ++i) {
            if (i != nums[i]) {
                return i;
            }
        }
    }
};
