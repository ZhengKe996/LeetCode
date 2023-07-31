#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int j = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); ++i) {
            while (i < j && numbers[i] + numbers[j] > target) j--;
            if (i < j && numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> numbers{2, 7, 11, 15};
    int target = 9;
    vector<int> res = s.twoSum(numbers, target);
    vector<int> numbers2{2, 3, 4};
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    int target2 = 6;
    vector<int> res2 = s.twoSum(numbers2, target2);
    for (int i = 0; i < res2.size(); ++i) {
        cout << res2[i] << " ";
    }
    return 0;
}
