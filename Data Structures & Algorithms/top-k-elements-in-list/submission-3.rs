use std::collections::HashMap;
use std::collections::BTreeMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
    let mut freq_map: HashMap<i32, i32> = HashMap::new();
    for num in nums {
        *freq_map.entry(num).or_default() += 1;
    }
    let mut ordered_map: BTreeMap<i32, Vec<i32>> = BTreeMap::new();
    for entry in freq_map {
        ordered_map.entry(entry.1).or_default().push(entry.0);
    }
    let mut res = Vec::with_capacity(k as usize);
    let mut k = k;
    while k > 0 {
        let val = ordered_map.pop_last().expect("Exists").1;
        for num in val {
            res.push(num);
            k -= 1;
        }
    }
    res
}
}
