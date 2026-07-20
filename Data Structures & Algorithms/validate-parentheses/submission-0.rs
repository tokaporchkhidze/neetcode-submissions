impl Solution {
    const OPEN_PARENTHESES: char = '(';
    const CLOSE_PARENTHESES: char = ')';

    const OPEN_BRACE: char = '{';
    const CLOSE_BRACE: char = '}';

    const OPEN_BRACKET: char = '[';
    const CLOSE_BRACKET: char = ']';

    pub fn is_valid(s: String) -> bool {
        let mut symbol_stack = vec![];
        for c in s.chars() {
            match c {
                Self::OPEN_PARENTHESES => symbol_stack.push(Self::CLOSE_PARENTHESES),
                Self::OPEN_BRACKET => symbol_stack.push(Self::CLOSE_BRACKET),
                Self::OPEN_BRACE => symbol_stack.push(Self::CLOSE_BRACE),
                Self::CLOSE_PARENTHESES | Self::CLOSE_BRACKET | Self::CLOSE_BRACE
                    if Some(c) != symbol_stack.pop() =>
                {
                    return false;
                }
                _ => {}
            };
        }
        symbol_stack.is_empty()
    }
}