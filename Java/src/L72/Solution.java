package L72;

public class Solution {
    public int minDistance(String word1, String word2) {

        int n = word1.length(), m = word2.length();
        word1 = " " + word1;
        word2 = " " + word2;

        int[][] f = new int[n + 1][m + 1];

        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m + 1; j++) {
                f[i][j] = (int) 1e9;
            }
        }

        for (int i = 0; i <= n; i++) {
            f[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            f[0][j] = j;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = Math.min(Math.min(f[i][j - 1] + 1, f[i - 1][j] + 1),
                        f[i - 1][j - 1] + (word1.charAt(i) != word2.charAt(j) ? 1 : 0));
            }
        }
        return f[n][m];
    }

    public static void main(String[] args) {
        String word1 = "horse", word2 = "ros";
        Solution solution = new Solution();
        System.out.println(solution.minDistance(word1, word2));
    }
}
