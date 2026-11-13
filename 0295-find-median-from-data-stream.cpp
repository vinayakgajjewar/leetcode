#include <cassert>
#include <queue>
#include <vector>

using namespace std;

// This is my solution from 2026-11-09. TODO: apparently there is a faster
// solution and i would like to know what it is. the time complexity of
// findMedian() is O(1) and the time complexity of addNum() is O(log N).
class MedianFinder
{
  public:
    // idea: use a max-heap to store the largest small number and a min-heap to
    // store the smallest large number. after adding a number, you need to make
    // sure that they have the same size (or are off by only one). we can decide
    // that the max-heap (low numbers) is allowed to store 1 more element than
    // the min heap.

    // if the sizes are the same, return the mean of the min and the max. if the
    // low numbers stores 1 more element, return the max of the low numbers.

    // when you add a number, you need to push the new number into the correct
    // heap and then rebalance if necessary

    // max heap by default
    priority_queue<int> low_nums;

    // note that you need to specify the underlying container as well as the
    // comparator. think through the comparator this way: elements that return
    // "false" when they are on the left side of the comparator will bubble to
    // the top, which is why the default max heap uses std::less.
    priority_queue<int, vector<int>, greater<int>> high_nums;

    MedianFinder()
    {
    }

    void addNum(int num)
    {

        // this is the tricky bit! i originally had a bunch of edge cases here,
        // but always pushing the new element into the max heap simplifies
        // things considerably.

        // NOTE: it is PUSH not INSERT for Cpp priority queue

        assert((low_nums.size() == high_nums.size()) || (low_nums.size() == 1 + high_nums.size()));

        // here's the pattern: add it to highs then move the min element of
        // highs to lows. this effectively adds a new element to lows but the
        // heaps definitely do not overlap. IMPORTANT: this pattern is probably
        // worth committing to memory.
        high_nums.push(num);
        low_nums.push(high_nums.top());
        high_nums.pop();

        // at this point, low_nums either contains 1 more element or 2 more
        // elements.
        if (low_nums.size() == 2 + high_nums.size())
        {
            high_nums.push(low_nums.top());
            low_nums.pop();
        }
    }

    double findMedian()
    {
        if (low_nums.size() == high_nums.size())
        {
            double l = (double)low_nums.top();
            double r = (double)high_nums.top();
            return ((l + r) / 2);
        }
        else
        {
            assert(low_nums.size() == 1 + high_nums.size());
            // return max of low nums
            return (double)low_nums.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */