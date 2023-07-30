package L42;

import org.w3c.dom.css.Rect;

import java.util.Deque;
import java.util.LinkedList;
import java.util.Stack;

public class Solution {
    private static int[] preMax;
    private static int[] sufMax;

    /**
     * 前缀后缀最大值
     *
     * @param height
     * @return
     */
    public static int trap(int[] height) {
        int n = height.length;
        preMax = new int[n];
        sufMax = new int[n];
        preMax[0] = height[0];

        for (int i = 1; i < n; i++) {
            preMax[i] = Math.max(preMax[i - 1], height[i]);
        }
        sufMax[n - 1] = height[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            sufMax[i] = Math.max(sufMax[i + 1], height[i]);
        }

        int ans = 0;
        // 枚举每个数条
        for (int i = 1; i < n - 1; i++) {
            int up = Math.min(preMax[i - 1], sufMax[i + 1]);
            int bottom = height[i];
            if (up > bottom) { // 能存水
                ans += (up - bottom);
            }
        }
        return ans;

    }


    private static class Rect {
        int width;
        int height;

        public Rect(int width, int height) {
            this.width = width;
            this.height = height;
        }
    }

    private static Stack<Rect> s = new Stack<>();

    /**
     * 横向考虑
     *
     * @param heights
     * @return
     */
    public static int trap2(int[] heights) {
        int ans = 0;
        for (int height : heights) {
            int accumulatedWidth = 0; // 累加宽度
            while (!s.empty() && s.peek().height <= height) {
                int bottom = s.peek().height;
                accumulatedWidth += s.peek().width;
                s.pop();

                if (s.empty()) {// 栈为空 则最左侧水要流走
                    continue;
                }
                // 以bottom为底的横块水最高可以到up（左右两侧的高度的min）
                int up = Math.min(height, s.peek().height);
                ans += accumulatedWidth * (up - bottom);
            }
            s.push(new Rect(accumulatedWidth + 1, height));
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        int trap = trap(height);
        int trap2 = trap2(height);
        System.out.println(trap + " " + trap2);
    }
}
