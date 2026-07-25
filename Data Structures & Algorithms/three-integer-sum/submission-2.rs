impl Solution {
    pub fn three_sum(mut nums: Vec<i32>) -> Vec<Vec<i32>> {
        nums.sort_unstable();
        let mut res = vec![];
        for i in 0..nums.len()-2 {
            let num = nums[i];

            if i > 0 && num == nums[i - 1] {
                continue;
            }
            let mut left = i + 1;
            let mut right = nums.len() - 1;
            while left < right {
                if nums[left] + nums[right] + num == 0 {
                    res.push(vec![num, nums[left], nums[right]]);
                    left += 1;
                    right -= 1;
                    while left < right && nums[left] == nums[left - 1] {
                        left += 1;
                    }
                    while left < right && nums[right] == nums[right + 1] {
                        right -= 1;
                    }
                } else if nums[left] + nums[right] + num < 0 {
                    left += 1;
                } else {
                    right -= 1;
                }
            }
        }
        res
    }

}
