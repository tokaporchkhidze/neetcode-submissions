class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto const largest_pile{std::ranges::max(piles)};
        int min{1};
        int max{largest_pile};
        int latest_answer{std::numeric_limits<int>::max()};
        while(min <= max) {
            int curr_k{(max + min) / 2};
            int64_t sum{};
            for (auto pile : piles) {
                sum += std::ceil(static_cast<double>(pile) / curr_k);
            }
            if (sum > h) {
                min = curr_k + 1;
            } else {
                latest_answer = std::min(curr_k, latest_answer);
                max = curr_k - 1;
            }
        }
        return latest_answer;
    }
};
