class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left{}, right{static_cast<int>(nums.size()) - 1};
        while (left < right) {
            int mid{(left + right) / 2};
            if (nums[right] > nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        int min_index{left};

        left = 0;
        right = nums.size() - 1;
        if(nums[min_index] <= target && nums[right] >= target) {
            left = min_index;
        } else {
            right = min_index - 1;
        }
        while (left <= right) {
            int mid{(left + right) / 2};
            if(nums[mid] == target) {
                return mid;
            }
            if(nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
