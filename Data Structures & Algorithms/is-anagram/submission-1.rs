impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t .len() {
            return false;
        }
        let mut hash_table = [0; 26];
        for c in s.chars() {
            hash_table[(c as usize) - ('a' as usize)] += 1;
        }
        for c in t.chars() {
            hash_table[(c as usize) - ('a' as usize)] -= 1;
        }
        hash_table.iter().all(|&count| {
            count == 0
        })
    }
}
