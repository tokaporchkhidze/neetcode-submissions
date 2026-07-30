class Solution {
public:
    int hammingWeight(uint32_t n) {
        int counter{};
        for (auto i{0}; i < 32; i++) {
            if( (n >> i) & 1 == 1) {
                ++counter;
            }
        }
        return counter;
    }
};
