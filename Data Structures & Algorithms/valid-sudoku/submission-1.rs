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
            let square_index = (i / 3) * 3 + j / 3;
            
            if !row_hashes[i].insert(val) ||
             !col_hashes[j].insert(val) || 
             !square_hashes[square_index].insert(val)
            {
                return false;
            }
        }
    }

    true
    }
}
