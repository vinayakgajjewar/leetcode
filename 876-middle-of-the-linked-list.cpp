
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode *middleNode(ListNode *head) {

        /*
         * This is a classic two pointer problem. They both start at the head
         * node. First, one pointer goes forward by one element. Then, the other
         * pointer goes forward by two elements. When the faster pointer reaches
         * the end of the list, we know that the slower pointer is at the middle
         * of the list.
         */
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (!fast->next) return slow;
            fast = fast->next;
        }
        return slow;
    }
};