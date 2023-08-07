package L1143;

public class Solution {
    public int longestCommonSubsequence(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        text1 = " " + text1;
        text2 = " " + text2;
        int[][] f = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                } else {
                    f[i][j] = Math.max(f[i - 1][j], f[i][j - 1]);
                }
            }
        }
        return f[m][n];
    }

    public int longestCommonSubsequence2(String text1, String text2) {
        int m = text1.length(), n = text2.length();
        text1 = " " + text1;
        text2 = " " + text2;
        int[][] f = new int[m + 1][n + 1];
        int[][] preType = new int[m + 1][n + 1];
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1.charAt(i) == text2.charAt(j)) {
                    f[i][j] = f[i - 1][j - 1] + 1;
                    preType[i][j] = 2;
                } else {
                    if (f[i - 1][j] > f[i][j - 1]) {
                        f[i][j] = f[i - 1][j];
                        preType[i][j] = 0;
                    } else {
                        f[i][j] = f[i][j - 1];
                        preType[i][j] = 1;
                    }
                }
            }
        }
        print(text1, text2, preType, m, n);
        return f[m][n];
    }

    void print(String text1, String text2, int[][] preType, int i, int j) {
        if (i == 0 || j == 0)
            return;

        if (preType[i][j] == 0)
            print(text1, text2, preType, i - 1, j);
        else if (preType[i][j] == 1)
            print(text1, text2, preType, i, j - 1);
        else
            print(text1, text2, preType, i - 1, j - 1);
    }
}
