package L433;

import java.util.*;

public class Solution {
    private Map<String, Integer> depth = new HashMap();
    private Set<String> hashBank = new HashSet<String>();

    public int minMutation(String startGene, String endGene, String[] bank) {
        depth.put(startGene, 0);
        for (String seq : bank) hashBank.add(seq);
        if (!hashBank.contains(endGene)) return -1;
        Queue<String> queue = new ArrayDeque<>();
        queue.add(startGene);
        char[] gene = {'A', 'C', 'G', 'T'};
        while (!queue.isEmpty()) {
            String s = queue.poll();
            for (int i = 0; i < 8; ++i) {
                for (int j = 0; j < 4; ++j) {
                    if (gene[j] != s.charAt(i)) {
                        StringBuffer ns = new StringBuffer(s);
                        ns.setCharAt(i, gene[j]);
                        if (!hashBank.contains(ns)) continue;
                        if (depth.containsKey(ns)) continue;
                        depth.put(ns.toString(), depth.get(s) + 1);
                        queue.add(ns.toString());
                        if (ns.toString() == endGene) return depth.get(ns.toString());
                    }
                }
            }
        }
        return -1;
    }

    public int minMutation2(String startGene, String endGene, String[] bank) {
        Set<String> cnt = new HashSet<String>();
        Set<String> visited = new HashSet<String>();
        char[] keys = {'A', 'C', 'G', 'T'};
        for (String w : bank) {
            cnt.add(w);
        }
        if (startGene.equals(endGene)) {
            return 0;
        }
        if (!cnt.contains(endGene)) {
            return -1;
        }
        Queue<String> queue = new ArrayDeque<String>();
        queue.offer(startGene);
        visited.add(startGene);
        int step = 1;
        while (!queue.isEmpty()) {
            int sz = queue.size();
            for (int i = 0; i < sz; i++) {
                String curr = queue.poll();
                for (int j = 0; j < 8; j++) {
                    for (int k = 0; k < 4; k++) {
                        if (keys[k] != curr.charAt(j)) {
                            StringBuffer sb = new StringBuffer(curr);
                            sb.setCharAt(j, keys[k]);
                            String next = sb.toString();
                            if (!visited.contains(next) && cnt.contains(next)) {
                                if (next.equals(endGene)) {
                                    return step;
                                }
                                queue.offer(next);
                                visited.add(next);
                            }
                        }
                    }
                }
            }
            step++;
        }
        return -1;
    }


    public static void main(String[] args) {
        Solution solution = new Solution();

        String start = "AACCGGTT", end = "AACCGGTA";
        String[] bank = {"AACCGGTA"};
        int ans = solution.minMutation2(start, end, bank);
        System.out.println(ans);

        start = "AACCGGTT";
        end = "AAACGGTA";
        String[] bank2 = {"AACCGGTA", "AACCGCTA", "AAACGGTA"};
        ans = solution.minMutation2(start, end, bank2);
        System.out.println(ans);

        start = "AAAAACCC";
        end = "AACCCCCC";
        String[] bank3 = {"AAAACCCC", "AAACCCCC", "AACCCCCC"};
        ans = solution.minMutation2(start, end, bank3);
        System.out.println(ans);
    }
}
