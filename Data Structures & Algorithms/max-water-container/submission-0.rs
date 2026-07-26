impl Solution {
    pub fn max_area(heights: Vec<i32>) -> i32 {
        let (mut left, mut right) = (0usize, heights.len() - 1);
        let mut max_area = i32::MIN;
        while left < right {
            let left_wall = heights[left];
            let right_wall = heights[right];
            let area = (right - left) as i32 * left_wall.min(right_wall);
            if area > max_area {
                max_area = area;
            }
            if left_wall < right_wall {
                left += 1;
            } else {
                right -= 1;
            }
        }
        max_area
    }
}
