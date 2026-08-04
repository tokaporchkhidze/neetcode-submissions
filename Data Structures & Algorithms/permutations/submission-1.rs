impl Solution {
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut used_nums = vec![false; nums.len()];
        let mut res = vec![];
        let mut curr_path = vec![];
        Self::backtrack(&nums, &mut used_nums, &mut curr_path, &mut res);
        res
    }

    fn backtrack(nums: &Vec<i32>, used_nums: &mut Vec<bool>, curr_path: &mut Vec<i32>, res: &mut Vec<Vec<i32>>) {
        if curr_path.len() == nums.len() {
            res.push(curr_path.clone());
            return;
        }

        for (i, &num) in nums.iter().enumerate() {
            if used_nums[i] {
                continue;
            }
            curr_path.push(num);
            used_nums[i] = true;
            Self::backtrack(nums, used_nums, curr_path, res);
            curr_path.pop();
            used_nums[i] = false;
        }
    }
}
