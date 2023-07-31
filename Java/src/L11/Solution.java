package L11;

public class Solution {
    public static int maxArea(int[] height) {
        int i = 0, j = height.length - 1, ans = 0;
        while (i < j) {
            ans = Math.max(ans, Math.min(height[i], height[j]) * (j - i));
            if (height[i] <= height[j]) i++;
            else j--;
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int area = maxArea(height);
        System.out.println(area);
        int[] height2 = {1, 1};
        int area2 = maxArea(height2);
        System.out.println(area2);
    }
}
