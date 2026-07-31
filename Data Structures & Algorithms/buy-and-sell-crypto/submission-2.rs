impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut res = i32::MIN;
        let mut buy_idx = 0;
        for (i, &num) in prices.iter().enumerate().skip(1) {
            if num < prices[buy_idx] {
                buy_idx = i;
                continue;
            }
            res = std::cmp::max(num - prices[buy_idx], res);
        }
        std::cmp::max(res, 0)
    }
}
