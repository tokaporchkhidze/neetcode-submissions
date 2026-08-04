impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        if s1.len() > s2.len() {
            return false;
        }
        let mut chars = [0i32; 26];
        for &c in s1.as_bytes().iter() {
            chars[(c - b'a') as usize] += 1;
        }
        for sub in s2.as_bytes().windows(s1.len()) {
            let mut curr_chars = chars.clone();
            for c in sub.iter() {
                curr_chars[(c - b'a') as usize] -= 1;
            }
            if curr_chars.iter().all(|&count| {count == 0}) {
                return true;
            }
        }
        false
    }
}
