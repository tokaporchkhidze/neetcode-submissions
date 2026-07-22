impl Solution {
    pub fn daily_temperatures(temperatures: Vec<i32>) -> Vec<i32> {
        let mut res:Vec<i32> = vec![0; temperatures.len()];
        let mut stack: Vec<usize>= Vec::with_capacity(temperatures.len());
        for i in 0..temperatures.len() {
            while let Some(&prev) = stack.last() {
                if temperatures[prev] >= temperatures[i] {
                    break;
                }
                stack.pop();
                res[prev] = (i - prev) as i32;
            }
            stack.push(i);
        }

        res
    }
}