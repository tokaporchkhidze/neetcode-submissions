
use std::fmt::Write as Write2;
impl Solution {
    const DELIMITER: char = '#';
    pub fn encode(strs: Vec<String>) -> String {
        let mut res = String::new();
        for s in strs {
            let _ = write!(res, "{}{}{}", s.len(), Self::DELIMITER, s);
        }
        res
    }

    pub fn decode(s: String) -> Vec<String> {
        let mut res = vec![];
        let mut offset = 0;
        while let Some(relative_idx) = s[offset..].find(Self::DELIMITER) {
            let abs_idx = offset + relative_idx;

            let part_length = s[offset..abs_idx].parse::<usize>().unwrap();

            let start = abs_idx + Self::DELIMITER.len_utf8();
            let end = start + part_length;

            res.push(s[start..end].to_string());
            offset = end;
        }
        res
    }
}
