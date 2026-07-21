struct MinStack {
    min: i32,
    main_stack: Vec<i32>,
    min_stack: Vec<i32>,
}

impl MinStack {
    pub fn new() -> Self {
        Self {
            min: i32::MAX,
            main_stack: Vec::new(),
            min_stack: Vec::new(),
        }
    }

    pub fn push(&mut self, val: i32) {
        self.main_stack.push(val);
        if let Some(&min_last) = self.min_stack.last() {
            self.min_stack.push(val.min(min_last));
        } else {
            self.min_stack.push(val);
        }
    }

    pub fn pop(&mut self) {
        self.main_stack.pop().expect("Always called on non-empty");
        self.min_stack.pop().expect("Always called on non-empty");
    }

    pub fn top(&self) -> i32 {
        *self.main_stack.last().expect("Always called on non-empty")
    }

    pub fn get_min(&self) -> i32 {
        *self.min_stack.last().expect("Always called on non-empty")
    }
}