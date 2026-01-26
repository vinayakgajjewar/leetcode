struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
 * For both the iterative and the recursive solutions, do not forget that the tail
 * of the list needs to explicitly be set to point to NULL.
 */
class Solution {
public:
    ListNode *reverseListRecursive(ListNode *head) {
        if (!head || !head->next)
            return head;
        ListNode *curr = reverseListRecursive(head->next);
        ListNode *newHead = curr;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = head;
        head->next = nullptr;
        return newHead;
    }

    /*
     * Don't forget to set the next pointer of the old head to nullptr! I forgot
     * to do that.
     */
    ListNode *reverseList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *back = head;
        ListNode *front = head->next;
        back->next = nullptr;
        while (front) {
            ListNode *temp = front->next;
            front->next = back;
            back = front;
            front = temp;
        }
        return back;
    }
};