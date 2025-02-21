#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static string addBinary(string a, string b) {
        string result;
        int carry = 0;
        int a_index = static_cast<int>(a.length()) - 1;
        int b_index = static_cast<int>(b.length()) - 1;
        while (a_index >= 0 || b_index >= 0 || carry > 0) {
            if (a_index >= 0) {
                carry += a[a_index] - '0';
            }
            --a_index;
            if (b_index >= 0) {
                carry += b[b_index] - '0';
            }
            --b_index;
            result += (carry % 2) + '0';
            carry /= 2;
        }
        reverse(begin(result), end(result));
        return result;
    }
};

int main() {
    cout << Solution::addBinary("11", "1") << endl;
    cout << Solution::addBinary("1010", "1011") << endl;
}