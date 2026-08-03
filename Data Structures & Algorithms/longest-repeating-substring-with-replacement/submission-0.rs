impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut left = 0;
        let mut res = 0;
        let mut frequencies = [0; 26];
        for (i, c) in s.as_bytes().iter().enumerate() {
            let curr = c - 'A' as u8;
            frequencies[curr as usize] += 1;
            let max_freq = frequencies.iter().max().unwrap();
            if (i - left + 1) as i32 - max_freq <= k {
                res = std::cmp::max(i - left + 1, res);
            } else {
                let c_to_remove = s.as_bytes()[left] - 'A' as u8;
                frequencies[c_to_remove as usize] -= 1;
                left += 1;
            }
        }
        res as i32
    }

}
