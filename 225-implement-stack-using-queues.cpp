#include <queue>

using namespace std;

class MyStack {
public:
    MyStack() {
        a_is_curr = true;
    }

    /*
     * We must maintain two queues, only one of which will be used to store
     * elements at a time. We also have to maintain some additional state that
     * tells us which queue we are currently using.
     */

    void push(int x) {
        if (a_is_curr) {
            queue_a.push(x);
        } else {
            queue_b.push(x);
        }
    }

    int pop() {
        int val;
        if (a_is_curr) {
            while (queue_a.size() > 1) {
                queue_b.push(queue_a.front());
                queue_a.pop();
            }
            val = queue_a.front();
            queue_a.pop();
        } else {
            while (queue_b.size() > 1) {
                queue_a.push(queue_b.front());
                queue_b.pop();
            }
            val = queue_b.front();
            queue_b.pop();
        }
        a_is_curr = !a_is_curr;
        return val;
    }

    int top() {
        int val;
        if (a_is_curr) {
            while (queue_a.size() > 1) {
                queue_b.push(queue_a.front());
                queue_a.pop();
            }
            val = queue_a.front();
            queue_b.push(val);
            queue_a.pop();
        } else {
            while (queue_b.size() > 1) {
                queue_a.push(queue_b.front());
                queue_b.pop();
            }
            val = queue_b.front();
            queue_a.push(val);
            queue_b.pop();
        }
        a_is_curr = !a_is_curr;
        return val;
    }

    bool empty() {
        return (queue_a.empty() && queue_b.empty());
    }

private:
    queue<int> queue_a;
    queue<int> queue_b;
    bool a_is_curr;
};