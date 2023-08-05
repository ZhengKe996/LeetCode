#include <iostream>

using namespace std;

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (guess(mid) <= 0) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

private:
    int guess(int x) {

    }
};

int main() {
    Solution s;

    return 0;
}
