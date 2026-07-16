impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut res = vec![0; nums.len()];
        let mut prefix_vec: Vec<i32> = vec![1; nums.len()];
        let mut suffix_vec: Vec<i32> = vec![1; nums.len()];
        //
        // [1,  2,  4,  6]
        // [1,  1,  2,  8]
        // [48, 24, 6,  1]
        prefix_vec[0] = 1;
        for i in 1..nums.len() {
            prefix_vec[i] = prefix_vec[i - 1] * nums[i - 1];
        }
        suffix_vec[nums.len() - 1] = 1;
        for i in (0..nums.len() - 1).rev() {
            suffix_vec[i] = suffix_vec[i + 1] * nums[i + 1];
        }

        for i in 0..res.len() {
            res[i] = suffix_vec[i] * prefix_vec[i];
        }
        res
    }
}
