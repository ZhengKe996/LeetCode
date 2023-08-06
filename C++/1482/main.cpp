#include <iostream>

using namespace std;

class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        int latestBloom = 0;
        for (int bloom: bloomDay) {
            latestBloom = max(latestBloom, bloom);
        }
        int left = 0, right = latestBloom + 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (validateOnDay(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (right == latestBloom + 1)return -1;
        return right;
    }

private:
    bool validateOnDay(vector<int> &bloomDay, int m, int k, int now) {
        int bouquet = 0, consecutive = 0;
        for (int bloom: bloomDay) {
            if (bloom <= now) {
                consecutive++;
                if (consecutive == k) {
                    bouquet++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        return bouquet >= m;
    }
};

int main() {
    Solution s;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    int ans = s.minDays(bloomDay, m, k);
    cout << ans << endl;

    bloomDay = {1, 10, 3, 10, 2}, m = 3, k = 2;
    ans = s.minDays(bloomDay, m, k);
    cout << ans << endl;

    bloomDay = {7, 7, 7, 7, 12, 7, 7}, m = 2, k = 3;
    ans = s.minDays(bloomDay, m, k);
    cout << ans << endl;
    return 0;
}
