impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        if numbers.len() == 2 {
            return vec![1, 2];
        }
        let mut left = 0usize;
        let mut right = numbers.len() - 1;
        while left < right {
            if numbers[left] + numbers[right] == target {
                break;
            } else if numbers[left] + numbers[right] < target {
                left += 1;
            } else {
                right -= 1;
            }
        }
        vec![(left + 1) as i32, (right + 1) as i32]
    }
}
