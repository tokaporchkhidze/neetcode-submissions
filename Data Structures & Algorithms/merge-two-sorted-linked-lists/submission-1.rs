// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//     pub val: i32,
//     pub next: Option<Box<ListNode>>,
// }
//
// impl ListNode {
//     #[inline]
//     pub fn new(val: i32) -> Self {
//         ListNode { next: None, val }
//     }
// }

impl Solution {
    pub fn merge_two_lists(mut list1: Option<Box<ListNode>>, mut list2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {

        let mut dummy = Box::new(ListNode::new(0));

        let mut node = &mut dummy;

        while let (Some(l1), Some(l2)) = (list1.as_ref(), list2.as_ref()) {
            if l1.val < l2.val {
                node.next = list1;
                node = node.next.as_mut().unwrap();
                list1 = node.next.take();
            } else {
                node.next = list2;
                node = node.next.as_mut().unwrap();
                list2 = node.next.take();
            }
        }

        node.next = if list1.is_some() { list1 } else { list2 };

        dummy.next
    }
}

