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

/*
 * For both the iterative and the recursive solutions, do not forget that the tail
 * of the list needs to explicitly be set to point to NULL.
 */
class Solution
{
  public:
    ListNode *reverseListRecursive(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *curr = reverseListRecursive(head->next);
        ListNode *newHead = curr;
        while (curr->next)
        {
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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *back = head;
        ListNode *front = head->next;
        back->next = nullptr;
        while (front)
        {
            ListNode *temp = front->next;
            front->next = back;
            back = front;
            front = temp;
        }
        return back;
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
// This is my solution from 2026-11-13. Important to note that you need to set
// head->next to nullptr since it is going to be the tail of the new list. It is
// also important that you grab a pointer to the node after next so that you can
// increment the pointers correctly.
class Solution
{
  public:
    ListNode *reverseList(ListNode *head)
    {
        // trivial cases
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;

        // at this point, we know that there are at least 2 nodes.
        ListNode *prev = head;
        ListNode *next = head->next;
        prev->next = nullptr;
        while (next != nullptr)
        {
            ListNode *after_next = next->next;
            next->next = prev;

            prev = next;
            next = after_next;
        }
        return prev;
    }
};