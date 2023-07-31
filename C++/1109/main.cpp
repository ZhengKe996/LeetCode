#include <iostream>

using namespace std;


/**
 * bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
 * 思路
 * 1    2   3   4   5
 * 10      -10
 *      20     -20
 *      25              -25
 * 10   45 -10 -20  0   -25（越界）
 * 10  55  45  25   25  (求前缀和)
 */
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> delta(n + 2, 0);
        for (vector<int> booking: bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            delta[first] += seats;
            delta[last + 1] -= seats;
        }

        vector<int> sum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + delta[i];
        }

        vector<int> ans(n, 0);
        for (int i = 1; i <= n; i++) {
            ans[i - 1] = sum[i];
        }
        return ans;
    }

};


int main() {
    return 0;
}
