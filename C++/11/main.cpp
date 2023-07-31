#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int i = 0, j = height.size() - 1;
        int ans = 0;
        while (i < j) {
            ans = max(ans, min(height[i], height[j]) * (j - i));
            if (height[i] <= height[j])i++;
            else j--;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
    int area = s.maxArea(height);
    cout << area << endl;

    vector<int> height2{1, 1};
    int area2 = s.maxArea(height2);
    cout << area2 << endl;
    return 0;
}
