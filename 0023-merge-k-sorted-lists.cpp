#include <cassert>
#include <queue>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr)
    {
    }

    explicit ListNode(int x) : val(x), next(nullptr)
    {
    }

    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

class Solution
{
  public:
    static ListNode *mergeKLists(vector<ListNode *> &lists)
    {
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
        for (ListNode *head : lists)
        {
            ListNode *curr = head;
            while (curr)
            {
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
        while (!list_elements.empty())
        {
            auto *curr = new ListNode(list_elements.top());
            tail->next = curr;
            tail = curr;
            list_elements.pop();
        }
        return head->next;
    }
};

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

// This is my solution from 2026-11-15. Note this method of defining a custom
// comparator for std::priority_queue. Apparently the time complexity is O(N log
// K) where N is the total number of nodes and K is the total number of lists.
// This is because we process each node exactly once and, for each node, each
// push operation costs O(log K) because the priority queue contains one node
// from each list. This is also why the space complexity is O(K), because the
// min-heap contains one node from each list.
class CompNode
{
  public:
    bool operator()(const ListNode *n1, const ListNode *n2)
    {
        // the rule is that if you return false when you are on the left, you
        // bubble to the top
        assert(n1 != nullptr);
        assert(n2 != nullptr);
        return (n1->val > n2->val);
    }
};
class Solution
{
  public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        // the naive solution is to iterate through each linked list and each
        // element in the linked list and insert that element where it is
        // supposed to go.

        // i think the solution that i'm supposed to arrive at is to use a
        // min-heap sorted on a ListNode's value and repeatedly pop off the
        // minimum of the heads of each linked list and chain them together. i
        // am not sure what the time and space complexity of this solution would
        // be, though. my guess is that the time complexity is O(Nlog N) where N
        // is the length of the output list.

        // trivial cases
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];

        // 1. put the heads of each list in a min-heap.
        priority_queue<ListNode *, vector<ListNode *>, CompNode> nodes;
        for (ListNode *head : lists)
        {
            // note that an entire list could just be null!
            if (head != nullptr)
                nodes.push(head);
        }
        // create a dummy head so that we can return its next pointer
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        // 2. while it is not empty, pop off the minimum element and append it
        //    to the end. then, add its next ListNode to the min-heap.
        while (!nodes.empty())
        {
            ListNode *top = nodes.top();
            nodes.pop();
            if (top->next != nullptr)
                nodes.push(top->next);
            curr->next = top;
            curr = top;
        }
        curr->next = nullptr;

        // return head->next
        return dummy->next;
    }
};