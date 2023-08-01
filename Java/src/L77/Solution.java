package L77;

import java.util.ArrayList;
import java.util.List;

class Solution {
    private int n = 0, k = 0;
    List<Integer> chosen = new ArrayList<Integer>();
    List<List<Integer>> ans = new ArrayList<List<Integer>>();

    public List<List<Integer>> combine(int n, int k) {
        this.n = n;
        this.k = k;
        recur(1);
        return ans;
    }

    private void recur(int i) {
        if (chosen.size() > k || chosen.size() + (n - i + 1) < k) return;

        if (i == n + 1) {
            if (chosen.size() == k) ans.add(new ArrayList<Integer>(chosen));
            return;
        }
        recur(i + 1);
        chosen.add(i);
        recur(i + 1);
        chosen.remove(chosen.size() - 1);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        List<List<Integer>> lists = solution.combine(4, 2);
        for (int i = 0; i < lists.size(); i++) {
            for (int j = 0; j < lists.get(i).size(); j++) {
                System.out.print(lists.get(i).get(j) + " ");
            }
            System.out.println();
        }
    }

}