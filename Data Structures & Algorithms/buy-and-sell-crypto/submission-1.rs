impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut res = i32::MIN;
        let mut buy_idx = 0;
        let mut sell_idx = 1;
        for (i, &num) in prices.iter().enumerate().skip(1) {
            if num < prices[buy_idx] {
                buy_idx = i;
                continue;
            }
            let curr_profit = num - prices[buy_idx];
            if curr_profit > res {
                res = curr_profit;
            }
        }
        if res < 0 {
            0
        } else {
            res
        }
    }
}
