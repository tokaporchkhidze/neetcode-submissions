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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1 && !list2) {
            return nullptr;
        }
        ListNode *head{};
        if (list1 && list2) {
            if (list1->val <= list2->val) {
                head = list1;
                head->next = mergeTwoLists(list1->next, list2);
            } else if (list1->val > list2->val) {
                head = list2;
                head->next = mergeTwoLists(list1, list2->next);
            }
        } else if (list1) {
            head = list1;
            head->next = mergeTwoLists(list1->next, list2);
        } else {
            head = list2;
            head->next = mergeTwoLists(list1, list2->next);
        }
        return head;
    }
};
