impl Solution {
    pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let unique_set = nums.iter().copied().collect::<HashSet<i32>>();
        for &num in nums.iter() {
            if !unique_set.contains(&(num - 1)) {
                let mut sequence_start = num;
                let mut sequence_length = 1;
                while unique_set.contains(&(sequence_start + 1)) {
                    sequence_start += 1;
                    sequence_length += 1;
                }
                if sequence_length > res {
                    res = sequence_length;
                }
            }
        }
        res
    }
}
