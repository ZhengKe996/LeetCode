#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int len = digits.size();
        for (int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0)return digits;
        }
        vector<int> ans(len + 1);
        ans[0] = 1;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> digits = {4, 3, 2, 1};
    vector<int> res = s.plusOne(digits);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}
