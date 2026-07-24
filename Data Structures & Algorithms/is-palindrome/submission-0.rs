impl Solution {
    pub fn is_palindrome(s: String) -> bool {
        s.chars()
            .filter(|c| c.is_alphanumeric())
            .zip(s.chars().rev().filter(|c| c.is_alphanumeric()))
            .all(|(a, b)| {
                char::eq_ignore_ascii_case(&a, &b)
            })
    }
}