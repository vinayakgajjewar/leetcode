#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static string addBinary(string a, string b) {
        /*
         * We are going to construct this string from the smallest digits to the
         * largest digits and then reverse it.
         */
        string result;
        int carry = 0;

        /*
         * Start at the end of the string (smallest digits first).
         */
        int i = static_cast<int>(a.length()) - 1;
        int j = static_cast<int>(b.length()) - 1;
        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += a[i] - '0';
            }
            --i;
            if (j >= 0) {
                carry += b[j] - '0';
            }
            --j;

            result += (carry % 2) + '0';
            carry /= 2;
        }
        /*
         * I guess this is how we can reverse strings in C++.
         */
        reverse(begin(result), end(result));
        return result;
    }
};

int main() {
    cout << Solution::addBinary("11", "1") << endl;
    cout << Solution::addBinary("1010", "1011") << endl;
}