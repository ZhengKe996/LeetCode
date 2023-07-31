package L304;

public class NumMatrix {
    int sum[][];

    public NumMatrix(int[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        sum = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
    }

    public static void main(String[] args) {
        int[][] nums = {{3, 0, 1, 4, 2},
                {5, 6, 3, 2, 1},
                {1, 2, 0, 1, 5},
                {4, 1, 0, 1, 7},
                {1, 0, 3, 0, 5}};
        NumMatrix numMatrix = new NumMatrix(nums);

        int r1 = numMatrix.sumRegion(2, 1, 4, 3);
        int r2 = numMatrix.sumRegion(1, 1, 2, 2);
        int r3 = numMatrix.sumRegion(1, 2, 2, 4);

        System.out.println(r1 + " " + r2 + " " + r3);
    }
}
