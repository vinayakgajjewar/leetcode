#include <vector>

using namespace std;

// this is my solution from 2026-10-31. the intuition is that the min stack is
// always the same size as the actual stack and stores the minimum value of the
// stack for each element. todo: according to neetcode, there is a smarter way
// to do this using only 1 stack, but i don't care right now.
class MinStack
{
  public:
    // this works like a normal stack
    vector<int> stack;

    // this stores the minimum element at each level of the stack. hence, it
    // will always have the same number of elements as the main stack.
    vector<int> min_stack;
    MinStack()
    {
    }

    void push(int value)
    {
        stack.push_back(value);

        if (min_stack.empty() || min_stack.back() > value)
        {
            min_stack.push_back(value);
        }
        else
        {
            min_stack.push_back(min_stack.back());
        }
    }

    void pop()
    {
        if (stack.empty())
            return;
        stack.pop_back();
        min_stack.pop_back();
    }

    int top()
    {
        if (stack.empty())
            return -1;
        int val = stack.back();
        return val;
    }

    int getMin()
    {
        return min_stack.back();
    }
};
