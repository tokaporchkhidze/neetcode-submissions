impl Solution {
    const SUM: &str = "+";
    const SUBTRACT: &str = "-";
    const MULTIPLY: &str = "*";
    const DIVIDE: &str = "/";

    pub fn eval_rpn(tokens: Vec<String>) -> i32 {
        let mut operands: Vec<i32> = vec![];
        for token in tokens {
            let operation: fn(i32, i32) -> i32 = match token.as_str() {
                Self::SUM => |a, b| a + b,
                Self::SUBTRACT => |a, b| a - b,
                Self::MULTIPLY => |a, b| a * b,
                Self::DIVIDE => |a, b| a / b,
                _ => {
                    operands.push(token.parse().expect("valid"));
                    continue;
                }
            };
            let b = operands.pop().expect("valid");
            let a = operands.pop().expect("valid");
            operands.push(operation(a, b));
        }
        operands.pop().expect("valid")
    }
}
