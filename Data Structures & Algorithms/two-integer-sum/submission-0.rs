impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut diff_hash = HashMap::new();
        for (i, &num) in nums.iter().enumerate() {
            let diff = target - num;
            if let Some(&j) = diff_hash.get(&diff) {
                return vec![j as i32, i as i32];
            }
            diff_hash.insert(num, i);
        }
        vec![]
    }
}
