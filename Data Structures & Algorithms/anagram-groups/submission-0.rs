use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
    let mut hash_table: HashMap<[i32; 26], Vec<String>> = HashMap::new();
    for string in strs {
        let mut hash_arr = [0; 26];
        for c in string.chars() {
            hash_arr[c as usize - 'a' as usize] += 1;
        }
        hash_table.entry(hash_arr).or_default().push(string);
    }
    hash_table.into_values().collect()
}
}
