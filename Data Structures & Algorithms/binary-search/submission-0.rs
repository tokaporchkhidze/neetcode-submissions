impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut low = 0;
        let mut high = nums.len();
        while low < high {
            let mid = (high + low) / 2;
            let num = nums[mid];
            match num.cmp(&target)  {
                Ordering::Equal => return mid as i32,
                Ordering::Less => low = mid + 1,
                Ordering::Greater => high = mid
            }
        }
        -1
    }
}
