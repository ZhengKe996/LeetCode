package L1482;

public class Solution {
    private boolean validateOnDay(int[] bloomDay, int m, int k, int now) {
        int bouquet = 0, consecutive = 0;
        for (int bloom : bloomDay) {
            if (bloom <= now) {
                consecutive++;
                if (consecutive == k) {
                    bouquet++;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
            }
        }
        return bouquet >= m;
    }

    public int minDays(int[] bloomDay, int m, int k) {
        int latestBloom = 0;
        for (int bloom : bloomDay) {
            latestBloom = Math.max(latestBloom, bloom);
        }
        int left = 0, right = latestBloom + 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (validateOnDay(bloomDay, m, k, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        if (right == latestBloom + 1)return -1;
        return right;
    }


    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] bloomDay = {1, 10, 3, 10, 2};
        int m = 3, k = 1;
        int ans = solution.minDays(bloomDay, m, k);
        System.out.println(ans);

        int[] bloomDay2 = {1, 10, 3, 10, 2};
        m = 3;
        k = 2;
        ans = solution.minDays(bloomDay2, m, k);
        System.out.println(ans);

        int[] bloomDay3 = {7, 7, 7, 7, 12, 7, 7};
        m = 2;
        k = 3;
        ans = solution.minDays(bloomDay3, m, k);
        System.out.println(ans);

    }
}
