impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut left = 0;
        let mut res = 0;
        let mut frequencies = [0usize; 26];
        let bytes = s.as_bytes();
        let k = k as usize;
        for (i, &c) in bytes.iter().enumerate() {
            let curr = c - b'A';
            frequencies[curr as usize] += 1;
            let max_freq = *frequencies.iter().max().unwrap();
            let curr_length = i - left + 1;
            if curr_length - max_freq <= k {
                res = std::cmp::max(curr_length, res);
            } else {
                let c_to_remove = bytes[left] - b'A';
                frequencies[c_to_remove as usize] -= 1;
                left += 1;
            }
        }
        res as i32
    }

}
