class Solution {
public:
    bool isBadVersion(int n);

    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low < high) {
            // Better way to calculate the average that doesn't risk integer
            // overflow.
            int middle = low + ((high - low) / 2);
            if (isBadVersion(middle)) {
                high = middle;
            } else {
                low = middle + 1;
            }
        }
        // Important: at the end, low will always be the first bad version.
        return low;
    }
};