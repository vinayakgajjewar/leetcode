struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseListRecursive(ListNode *head) {

        // Base case.
        if (!head || !head->next)
            return head;

        // Recursive case.
        ListNode *curr = reverseListRecursive(head->next);
        ListNode *newHead = curr;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = head;
        head->next = nullptr;
        return newHead;
    }

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

            // Increment our pointers.
            back = front;
            front = temp;
        }
        return back;
    }
};