/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        auto curr = &dummy;
        auto left_over{0};
        while(l1 || l2) {
            auto l1_val{0};
            if (l1) {
                l1_val = l1->val;
                l1 = l1->next;
            }
            auto l2_val{0};
            if (l2) {
                l2_val = l2->val;
                l2 = l2->next;
            }
            auto new_val{l1_val + l2_val + left_over};
            if(new_val < 10) {
                curr->next = new ListNode(new_val);
                curr = curr->next;
                left_over = 0;
            } else {
                auto left = new_val - 10;
                auto right{1};
                curr->next = new ListNode(left);
                curr = curr->next;
                left_over = 1;
            }
        }

        if(left_over != 0) {
            curr->next = new ListNode(1);
        }

        return dummy.next;
    }
};
