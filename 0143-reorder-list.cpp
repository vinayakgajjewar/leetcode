
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr)
    {
    }
    ListNode(int x) : val(x), next(nullptr)
    {
    }
    ListNode(int x, ListNode *next) : val(x), next(next)
    {
    }
};

// This is my solution from 2026-11-13. Note how you need to hold temp pointers
// to nodes you care about before you can't access them anymore. I do have a
// feeling that there is a better way to do this problem, though.
class Solution
{
  public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
            return;
        if (head->next == nullptr)
            return;

        // find the end of the linked list
        ListNode *left = head;
        ListNode *right = head;
        while (right->next != nullptr)
        {
            right = right->next;
        }

        while (left != right && left->next != right)
        {
            ListNode *left_next = left->next;
            left->next = right;
            right->next = left_next;
            left = left_next;

            ListNode *old_right = right;
            right = left;
            while (right->next != old_right)
            {
                right = right->next;
            }
        }

        right->next = nullptr;

        // while they are not at the same node or 1 edge away:
        // - grab a pointer to left's old next
        // - update left's next to be right
        // - update right's next to be left's old next
        // - update left to left's old next, update right to be right's prev (O(n) operation)

        // update right's next to be nullptr
    }
};