class Solution {
public:
    int findMin(vector<int> &nums) {
        auto left{0}, right{static_cast<int>(nums.size()) - 1}, mid{0};
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[right] > nums[mid]) {
                right = mid;
            } else  {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
