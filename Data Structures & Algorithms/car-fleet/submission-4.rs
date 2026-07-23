impl Solution {
    pub fn car_fleet(target: i32, position: Vec<i32>, speed: Vec<i32>) -> i32 {
        let mut cars: Vec<(i32, f64)> = position
            .into_iter()
            .zip(speed)
            .map(|(pos, speed)| (pos, (target - pos) as f64 / speed as f64))
            .collect();

        cars.sort_unstable_by_key(|&(distance, _)| {Reverse(distance)});
        let mut car_fleet = 0;
        let mut lead_time = f64::NEG_INFINITY;
        for (_, time) in cars {
            if time > lead_time {
                car_fleet += 1;
                lead_time = time;
            }
        }
        car_fleet

    }
}
