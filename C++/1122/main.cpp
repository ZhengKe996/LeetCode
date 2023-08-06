#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        unordered_map<int, int> arr2orders;
        for (int i = 0; i < arr2.size(); ++i) {
            arr2orders[arr2[i]] = i;
        }
        sort(arr1.begin(), arr1.end(), [&](int x, int y) {
            int xPos = arr2orders.find(x) != arr2orders.end() ? arr2orders[x] : arr2.size();
            int yPos = arr2orders.find(y) != arr2orders.end() ? arr2orders[y] : arr2.size();

            return xPos < yPos || (xPos == yPos && x < y);
        });
        return arr1;
    }

    vector<int> relativeSortArray2(vector<int> &arr1, vector<int> &arr2) {
        vector<int> count(1001, 0);
        for (int val: arr1) {
            count[val]++;
        }
        vector<int> ans;
        for (int val: arr2) {
            while (count[val] > 0) {
                ans.push_back(val);
                count[val]--;
            }
        }
        for (int i = 0; i <= 1000; ++i) {
            while (count[i] > 0) {
                ans.push_back(i);
                count[i]--;
            }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = {2, 1, 4, 3, 9, 6};
    vector<int> ans = s.relativeSortArray(arr1, arr2);
    vector<int> ans2 = s.relativeSortArray2(arr1, arr2);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " " << ans2[i] << endl;
    }

    return 0;
}
