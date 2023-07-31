#include <iostream>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0)return;
        sum = vector<vector<int>>(m + 1, vector<int>(n + 1));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + matrix[i - 1][j - 1] - sum[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }

private:
    vector<vector<int>> sum;
};

int main() {
    vector<vector<int>> nums = {{3, 0, 1, 4, 2},
                                {5, 6, 3, 2, 1},
                                {1, 2, 0, 1, 5},
                                {4, 1, 0, 1, 7},
                                {1, 0, 3, 0, 5}};

    NumMatrix *numMatrix = new NumMatrix(nums);
    int r1 = numMatrix->sumRegion(2, 1, 4, 3);
    int r2 = numMatrix->sumRegion(1, 1, 2, 2);
    int r3 = numMatrix->sumRegion(1, 2, 2, 4);
    cout << r1 << " " << r2 << " " << r3 << endl;
    return 0;
}
