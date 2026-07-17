impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {

        let mut row_hashes: [HashSet<char>; 9] = std::array::from_fn(|_| {HashSet::new()});
        let mut col_hashes: [HashSet<char>; 9] = std::array::from_fn(|_| {HashSet::new()});
        let mut square_hashes: [HashSet<char>; 9] = std::array::from_fn(|_| {HashSet::new()});

        for (i, row) in board.into_iter().enumerate() {

            for (j, val) in row.into_iter().enumerate() {
                if val == '.' {
                    continue;
                }
                let row_hash = &mut row_hashes[i];
                if row_hash.contains(&val) {
                    return false;
                }
                row_hash.insert(val);
                let col_hash = &mut col_hashes[j];
                if col_hash.contains(&val) {
                    return false;
                }
                col_hash.insert(val);
                let square_index = (i / 3) * 3 + j / 3;
                let square_hash = &mut square_hashes[square_index];
                if square_hash.contains(&val) {
                    return false;
                }
                square_hash.insert(val);
            }
        }

        true
    }
}
