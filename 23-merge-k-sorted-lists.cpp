#include <queue>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    explicit ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode *mergeKLists(vector<ListNode *> &lists) {
        /*
         * This is the type of problem that benefits a lot from using a priority
         * queue. Iterate through each element in each linked list and add its
         * value to the priority queue. Then, create a new linked list from the
         * elements in that priority queue.
         */

        /*
         * We can use greater<> when we want to sort in ascending order. We
         * could have made this a priority queue of list nodes instead of
         * integers, but either one is fine.
         */
        priority_queue<int, vector<int>, greater<>> list_elements;
        for (ListNode *head: lists) {
            ListNode *curr = head;
            while (curr) {
                list_elements.push(curr->val);
                curr = curr->next;
            }
        }

        /*
         * For ease of implementation, we'll create a dummy head node and return
         * the node it points to.
         */
        auto *head = new ListNode(-1);
        ListNode *tail = head;
        while (!list_elements.empty()) {
            auto *curr = new ListNode(list_elements.top());
            tail->next = curr;
            tail = curr;
            list_elements.pop();
        }
        return head->next;
    }
};