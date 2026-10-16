#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
  public:
    bool checkInclusion(string s1, string s2)
    {

        // This is the naive solution that runs in O(M*N) time complexity. We
        // could improve this solution by reusing the substring frequency table
        // and modifying it as we advance through s2. I believe that would
        // improve the time complexity to O(N).
        int m = s1.size();
        int n = s2.size();

        if (n < m)
            return false;

        unordered_map<char, int> s1_freqs;
        for (int i = 0; i < m; i++)
        {
            s1_freqs[s1.at(i)]++;
        }

        for (int i = 0; i < n - m + 1; i++)
        {
            unordered_map<char, int> substr_freqs;
            for (int j = i; j < i + m; j++)
            {
                substr_freqs[s2.at(j)]++;
            }
            if (s1_freqs == substr_freqs)
                return true;
        }
        return false;
    }

    // This is the optimized solution that runs in O(N) time complexity because
    // we reuse the frequency table. Note how you have to use erase() to make
    // the equality check work. Note also the classic 2-pointer sliding window
    // technique going on here.
    bool checkInclusion(string s1, string s2)
    {
        int m = s1.size();
        int n = s2.size();

        if (n < m)
            return false;

        unordered_map<char, int> s1_freqs;
        unordered_map<char, int> sliding_freqs;
        for (int i = 0; i < m; i++)
        {
            s1_freqs[s1.at(i)]++;
            sliding_freqs[s2.at(i)]++;
        }
        // don't forget to check the 1st substring
        if (s1_freqs == sliding_freqs)
            return true;

        int left = 0;
        for (int right = m; right < n; right++)
        {
            sliding_freqs[s2.at(right)]++;
            sliding_freqs[s2.at(left)]--;

            // necessary for equality check
            if (sliding_freqs[s2.at(left)] == 0)
            {
                sliding_freqs.erase(s2.at(left));
            }
            if (s1_freqs == sliding_freqs)
                return true;
            left++;
        }
        return false;
    }
};