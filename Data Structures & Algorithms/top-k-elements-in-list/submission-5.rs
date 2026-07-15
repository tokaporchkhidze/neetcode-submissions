use std::collections::HashMap;
use std::collections::BTreeMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let n = nums.len();

        let mut freq_map: HashMap<i32, i32> = HashMap::new();
        for num in nums {
            *freq_map.entry(num).or_default() += 1;
        }
        
        let mut bucket_list = vec![vec![]; n + 1];

        for (num, freq) in freq_map {
            bucket_list[freq as usize].push(num);
        }

        let mut res = Vec::with_capacity(k as usize);
        for bucket in bucket_list.iter().rev() {
            for &num in bucket {
                res.push(num);
            }
            if res.len() == k as usize {
                return res;
            }
        }
        res
    
    }
}
