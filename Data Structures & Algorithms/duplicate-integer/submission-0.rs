use std::collections::HashSet;

impl Solution {
    pub fn has_duplicate(nums: Vec<i32>) -> bool {
        let mut duplicates = HashSet::with_capacity(nums.len());
        for num in nums {
            if !duplicates.insert(num) {
                return true;
            }
        }
        false
    }
}
