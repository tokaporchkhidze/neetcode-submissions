impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let (s1, s2) = (s1.as_bytes(), s2.as_bytes());
        if s1.len() > s2.len() {
            return false;
        }
        let mut target = [0i32; 26];
        let mut fixed_window = [0i32; 26];
        for i in 0..s1.len() {
            target[(s1[i] - b'a') as usize] += 1;
            fixed_window[(s2[i] - b'a') as usize] += 1;
        }
        if target == fixed_window {
            return true;
        }

        let mut left = 0;
        for i in s1.len()..s2.len() {
            fixed_window[(s2[left] - b'a') as usize] -= 1;
            fixed_window[(s2[i] - b'a') as usize] += 1;
            if target == fixed_window {
                return true;
            }
            left += 1;
        }
        false
    }
}
