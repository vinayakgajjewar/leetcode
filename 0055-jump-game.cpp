#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// this is my naive solution from 2026-11-05. it gives "time limit exceeded" on
// leetcode.
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        // this is a naive solution, but what you can do is start at the end index and figure out what positions can
        // jump to the end index. for each one, you can figure out what positions can jump to that index, and so on.
        // this would make some sort of tree i think, so you can choose either bfs or dfs.

        int n = nums.size(); // guaranteed not empty

        // this is a queue of positions (indexes into nums)
        queue<int> reaches_end;
        reaches_end.push(n - 1);

        while (!reaches_end.empty())
        {

            // todo: need to review queue functions
            int pos = reaches_end.front();
            reaches_end.pop();
            if (pos == 0)
                return true;
            for (int i = pos - 1; i >= 0; i--)
            {
                // i is the candidate pos and nums[i] is its jump distance
                if (i + nums[i] >= pos)
                {
                    reaches_end.push(i);
                }
            }
        }

        return false;
    }
};

// adding a visited set is also not sufficient to pass leetcode.
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        // this is a naive solution, but what you can do is start at the end index and figure out what positions can
        // jump to the end index. for each one, you can figure out what positions can jump to that index, and so on.
        // this would make some sort of tree i think, so you can choose either bfs or dfs.

        int n = nums.size(); // guaranteed not empty

        // this is a queue of positions (indexes into nums)
        queue<int> reaches_end;
        reaches_end.push(n - 1);

        // i think this is the optimization that we need to do
        unordered_set<int> visited_positions;

        while (!reaches_end.empty())
        {

            // note that for std::queue you push to the back and pop from the front
            int pos = reaches_end.front();
            reaches_end.pop();
            if (pos == 0)
                return true;

            if (visited_positions.contains(pos))
                continue;
            visited_positions.insert(pos);

            for (int i = pos - 1; i >= 0; i--)
            {
                // i is the candidate pos and nums[i] is its jump distance
                if (i + nums[i] >= pos)
                {
                    reaches_end.push(i);
                }
            }
        }

        return false;
    }
};

// moving from a queue to a stack passed leetcode, but it is far from optimal.
// the time complexity is O(n^2) because even though we have a visited set, we
// can still process each position and do O(n) work at each position.
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        // this is a naive solution, but what you can do is start at the end
        // index and figure out what positions can jump to the end index. for
        // each one, you can figure out what positions can jump to that index,
        // and so on. this would make some sort of tree i think, so you can
        // choose either bfs or dfs.

        int n = nums.size(); // guaranteed not empty

        // this is a queue of positions (indexes into nums) queue<int>
        // reaches_end;
        vector<int> reaches_end;
        // reaches_end.push(n - 1);
        reaches_end.push_back(n - 1);

        // i think this is the optimization that we need to do
        unordered_set<int> visited_positions;

        while (!reaches_end.empty())
        {

            // note that for std::queue you push to the back and pop from the
            // front

            // int pos = reaches_end.front();
            // reaches_end.pop();
            int pos = reaches_end.back();
            reaches_end.pop_back();
            if (pos == 0)
                return true;

            if (visited_positions.contains(pos))
                continue;
            visited_positions.insert(pos);

            for (int i = pos - 1; i >= 0; i--)
            {
                // i is the candidate pos and nums[i] is its jump distance
                if (i + nums[i] >= pos)
                {
                    // reaches_end.push(i);
                    reaches_end.push_back(i);
                }
            }
        }

        return false;
    }
};

// this is the best solution, which uses greedy. the runtime complexity is O(N).
// i guess the intuition is that this is better than the dfs/bfs solution
// because you do not need to explore every path, just keep moving backward and
// figure out the leftmost position that can reach the goal.
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int goal = n - 1;

        // iterate backwards starting at the position before the goal
        for (int i = goal - 1; i >= 0; i--)
        {
            // i is the position we are at right now, and nums[i] is the jump
            // distance at this position

            // if we can reach the current goal from this position, the goal is
            // now this position. note that the goal will only ever go
            // backwards.
            if (i + nums[i] >= goal)
            {
                goal = i;
            }
        }

        return (goal == 0);
    }
};

// This is my solution from 2026-11-06. i guess the intuition is that because
// you can jump to any position up to a maximum distance, moving the goal to the
// left never takes away a possible solution! which is why the greedy approach
// works here. i think if the problem was modified so that you can only jump to
// a particular distance, not a maximum of that distance, greedy would not work.
// this is an interesting problem because it is not immediately obvious that the
// best solution is greedy.
class Solution
{
  public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();

        int goal_pos = n - 1;

        for (int i = goal_pos - 1; i >= 0; i--)
        {
            // check if the current position can jump to the goal. if so, move
            // the goal to the current position.
            if (i + nums[i] >= goal_pos)
                goal_pos = i;
        }

        if (goal_pos == 0)
        {
            return true;
        }
        return false;
    }
};