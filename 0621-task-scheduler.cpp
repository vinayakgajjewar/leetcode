#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// This is my solution from 2026-11-04. The calculation itself is pretty
// intuitive but the thing that tripped me up is the conditional at the end
// where you compare with the length of the vector. The intuition there is that
// if you are given N distinct tasks to schedule, you need AT LEAST N slots just
// to run them all. It means that you are bottlenecked by the number of tasks
// you need to run, not the cooldown period. The time complexity is O(m) where m
// is the number of tasks.
class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freqs;
        for (char c : tasks)
        {
            freqs[c]++;
        }
        int max_freq = 0;
        for (const auto &[c, freq] : freqs)
        {
            if (max_freq < freq)
                max_freq = freq;
        }
        int num_max_freqs = 0;
        for (const auto &[_, freq] : freqs)
        {
            if (freq == max_freq)
            {
                num_max_freqs++;
            }
        }
        int sol = num_max_freqs + ((n + 1) * (max_freq - 1));
        if (sol < tasks.size())
        {
            return tasks.size();
        }
        return sol;
    }
};

// this is the max-heap solution from neetcode. i did this on 2026-11-04. this
// solution could be made a bit more intuitive by creating a task struct with
// all the relevant info todo: how would you determine the time complexity for
// this solution?
class Solution
{
  public:
    int leastInterval(vector<char> &tasks, int n)
    {
        unordered_map<char, int> freqs;
        for (char c : tasks)
        {
            freqs[c]++;
        }

        // it is interesting to note that, from this point on, the actual task
        // names do not matter, only their frequencies.

        // it's great that this is a max heap, but what's a more descriptive
        // name for this var? also, why do we only store the frequencies and not
        // the task with that frequency? todo: need to review priority_queue api
        // and runtime complexities. i think the intuition here is that the max
        // heap holds the tasks that are "runnable" and it has to be a max heap
        // because we want to run the runnable task with the highest remaining
        // frequency.
        priority_queue<int> runnable_counts;
        for (const auto &[_, freq] : freqs)
        {
            runnable_counts.push(freq);
        }

        // this is the thing we actually care about
        int time = 0;

        // the intuition here is that when we run a task, we will push it onto
        // the cooldown queue. and at the end of every time step, we will pop
        // tasks that are ready to run and put it back into the max heap. first:
        // remaining count after running, second: next available time
        queue<pair<int, int>> cooldown_q;

        while (!runnable_counts.empty() || !cooldown_q.empty())
        {
            time++;
            if (runnable_counts.empty())
            {
                // nothing is runnable, so fast-forward the clock. later, we
                // will move this task to the runnable max heap.
                time = cooldown_q.front().second;
            }
            else
            {
                // run the task with the highest remaining count and push it
                // onto the cooldown queue if there are runs left.
                int remaining = runnable_counts.top() - 1;
                runnable_counts.pop();
                if (remaining > 0)
                {
                    cooldown_q.push({remaining, time + n});
                }
            }

            // check if there are tasks that are now runnable and, if so, push
            // them onto the runnable max heap. note that at any time step, only
            // at most one task can become runnable because the cooldowns are
            // the same for each task. if this assumption is not true, this
            // would need to be a while-loop or something.
            if (!cooldown_q.empty() && cooldown_q.front().second == time)
            {
                runnable_counts.push(cooldown_q.front().first);
                cooldown_q.pop();
            }
        }

        // we know we are done when both the runnable max heap and the cooldown
        // queue are empty.
        return time;
    }
};