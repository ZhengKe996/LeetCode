package L1109;

public class Solution {
    /**
     * 𝐵1 = 𝐴1  𝐵𝑖 = 𝐴𝑖 − 𝐴(𝑖−1)  (2 ≤ 𝑖 ≤ 𝑛)
     *
     * @param bookings
     * @param n
     * @return
     */
    public static int[] corpFlightBookings(int[][] bookings, int n) {
        int[] delta = new int[n + 2];

        for (int[] booking : bookings) {
            int first = booking[0];
            int last = booking[1];
            int seats = booking[2];
            delta[first] += seats;
            delta[last + 1] -= seats;
        }

        int[] sum = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + delta[i];
        }

        int[] ans = new int[n];
        for (int i = 1; i <= n; i++) {
            ans[i - 1] = sum[i];
        }
        return ans;
    }

    public static void main(String[] args) {
        int[][] bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
        int n = 5;
        int[] ints = corpFlightBookings(bookings, n);
        for (int i = 0; i < ints.length; i++) {
            System.out.print(ints[i] + " ");
        }
    }
}
