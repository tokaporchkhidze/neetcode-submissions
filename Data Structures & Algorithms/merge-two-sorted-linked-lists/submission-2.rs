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
    pub fn merge_two_lists(
        list1: Option<Box<ListNode>>,
        list2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        if list1.is_none() {
            return list2;
        }

        if list2.is_none() {
            return list1;
        }

        if let (Some(mut l1), Some(mut l2)) = (list1, list2) {
            if l1.val < l2.val {
                l1.next = Self::merge_two_lists(l1.next, Some(l2));
                Some(l1)
            } else {
                l2.next = Self::merge_two_lists(Some(l1), l2.next);
                Some(l2)
            }
        } else {
            None
        }
    }
}


