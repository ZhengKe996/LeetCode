#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;


        if (n == -(1ll << 31)) return 1.0 / (myPow(x, -(n + 1)) * x);

        if (n < 0) return 1.0 / myPow(x, -n);

        double temp = myPow(x, n / 2);
        double ans = temp * temp;
        if (n % 2 == 1) ans *= x;

        return ans;
    }
};

int main() {
    Solution s;
    double ans = s.myPow(2.00000, -2);
    cout << ans << endl;
    ans = s.myPow(2.10000, 3);
    cout << ans << endl;
    ans = s.myPow(2.00000, 10);
    cout << ans << endl;
    return 0;
}
