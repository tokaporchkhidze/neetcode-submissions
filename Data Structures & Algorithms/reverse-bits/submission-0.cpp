class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res{};
        for(auto i{0}, j{31}; i < 32; ++i, --j) {
            uint32_t bit_to_set{n >> j & 1};
            res |= bit_to_set << i;
        }
        return res;
    }
};
