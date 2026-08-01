impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut unique_set = std::collections::HashSet::new();
        let mut left = 0;
        let mut longest = 0;
        let bytes_slice = s.as_bytes();
        for (i, &c) in bytes_slice.iter().enumerate() {
            if !unique_set.insert(c) {
                while bytes_slice[left as usize] != c {
                    unique_set.remove(&bytes_slice[left as usize]);
                    left += 1;
                }
                left += 1;
            } else {
                longest = longest.max(i as i32 - left + 1);
            }
        }
        longest
    }
}
