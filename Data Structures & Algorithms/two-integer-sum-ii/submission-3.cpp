class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> vec(2, 0);
        int i{0}, j{static_cast<int>(numbers.size()) - 1};
        for(; j > 0;) {
            int sum{numbers[i] + numbers[j]};
            if(sum == target) {
                vec[0] = i + 1;
                vec[1] = j + 1;
                break;
            } else if(sum < target) {
                ++i;
            } else {
                --j;
            }
        }
        return vec;
    }
};
