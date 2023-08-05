#include <iostream>

using namespace std;

class Solution {
public:
    long mySqrt(int x) {
        long l = 0, r = x;
        while (l < r) {
            long mid = l + ((r - l + 1) >> 1);
            if (mid <= x / mid) l = mid;
            else r = mid - 1;
        }
        return r;
    }

    int mySqrt2(int x) {
        return (int) (myRealSqrt(x));
    }

private:
    double myRealSqrt(double x) {
        double l = 0, r = x;
        while (r - l > 1e-7) {
            double mid = l + ((r - l) / 2);
            if (mid <= x / mid) l = mid;
            else r = mid;
        }
        return r;
    }
};

int main() {
    Solution s;
    int ans = s.mySqrt2(4);
    cout << ans;
    return 0;
}
