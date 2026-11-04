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

// this is my solution from 2026-11-03. i think using a stack of pairs is more
// intuitive than maintaining two stacks, even though they are equivalent.
// intuition: because it is a stack, the minimum value of the stack for each
// element is only dependent on the elements below it, which means the minimum
// value of the stack at the point that a value is pushed on will never change.
// therefore, you can keep track of the minimum value for each element. you can
// either use another stack or use a stack of pairs.
class MinStack2
{

    // 1st elem is value and 2nd elem is min value at that point
    vector<pair<int, int>> stack;

  public:
    MinStack()
    {
    }

    void push(int value)
    {
        if (stack.empty())
        {
            // stack is empty
            stack.emplace_back(value, value);
        }
        else
        {
            // stack is not empty
            int old_min = stack.back().second;
            if (value < old_min)
            {
                // there is a new min
                stack.emplace_back(value, value);
            }
            else
            {
                stack.emplace_back(value, old_min);
            }
        }
    }

    void pop()
    {
        stack.pop_back();
    }

    int top()
    {
        return stack.back().first;
    }

    int getMin()
    {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */