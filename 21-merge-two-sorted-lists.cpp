/*
 * 21-merge-two-sorted-lists.cpp
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/description/
 */

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    /*
     * Don't forget about the technique of using a dummy node to start the list!
     *
     * Also note how easy it is to handle the case where one list is longer than
     * the other.
     */
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode dummy;
        ListNode *dummy_ptr = &dummy;
        ListNode *curr_end = dummy_ptr;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                curr_end->next = list1;
                list1 = list1->next;
            } else {
                curr_end->next = list2;
                list2 = list2->next;
            }
            curr_end = curr_end->next;
        }
        if (list1) curr_end->next = list1;
        if (list2) curr_end->next = list2;
        return dummy_ptr->next;
    }
};