package L66;

public class Solution {
    public static int[] plusOne(int[] digits) {
        int len = digits.length;
        for (int i = len - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] %= 10;
            if (digits[i] != 0) return digits;
        }
        digits = new int[len + 1];
        digits[0] = 1;
        return digits;
    }

    public static void main(String[] args) {
        int[] digits = {4, 3, 2, 1};
        int[] result = plusOne(digits);

        for (int i = 0; i < result.length; i++) {
            System.out.println(result[i]);
        }
    }
}
