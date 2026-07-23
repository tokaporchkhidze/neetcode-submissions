impl Solution {
    pub fn car_fleet(target: i32, position: Vec<i32>, speed: Vec<i32>) -> i32 {
        let mut mono_stack: Vec<(i32, f32)> = vec![];
        for (i, pos) in position.into_iter().enumerate() {
            let distance = target - pos;
            let time = (distance as f32 / speed[i] as f32);
            mono_stack.push((distance, time));
        }
        mono_stack.sort_unstable_by_key(|&(distance, _)| {Reverse(distance)});
        println!("{:?}", mono_stack);
        let mut car_fleet = 1;
        let mut x = mono_stack.last().expect("valid").1;
        while let Some(&(_, time)) = mono_stack.last() {
            if time > x {
                car_fleet += 1;
                x = time;
            }
            mono_stack.pop();
        }
        car_fleet
    }
}
