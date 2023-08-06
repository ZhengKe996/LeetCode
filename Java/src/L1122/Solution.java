package L1122;

import java.util.*;
import java.util.stream.Collectors;

public class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        HashMap<Integer, Integer> hashMap = new HashMap<>();
        for (int i = 0; i < arr2.length; i++) {
            hashMap.put(arr2[i], i);
        }

        List<Integer> res = Arrays.stream(arr1).boxed().collect(Collectors.toList());

        Collections.sort(res, (num1, num2) -> {
            if (hashMap.containsKey(num1) || hashMap.containsKey(num2)) {
                return hashMap.getOrDefault(num1, 1000) - hashMap.getOrDefault(num2, 1000);
            } else {
                return num1 - num2;
            }
        });
        return res.stream().mapToInt(i -> i).toArray();
    }

    public int[] relativeSortArray2(int[] arr1, int[] arr2) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        // map 存储arr2中元素以及其对应的下标位置
        for (int i = 0; i < arr2.length; i++) {
            map.put(arr2[i], i);
        }
        Integer[] temp = new Integer[arr1.length];
        //将int[] arr1 转成 Integer[] temp,
        for (int i = 0; i < arr1.length; i++) {
            temp[i] = arr1[i];
        }
        //按自定义方式排序
        Arrays.sort(temp, new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                //若a和b都在arr2中，按map中存储的下标位置从小到大排序
                if (map.containsKey(a) && map.containsKey(b)) {
                    return map.get(a) - map.get(b);
                } else if (map.containsKey(a)) { //若只有a出现在arr2中，a排在前面
                    return -1;
                } else if (map.containsKey(b)) { //若只有b出现在arr2中，b排在前面
                    return 1;
                } else { //若a和b都不在arr2中，按其值从小到大排列
                    return a - b;
                }
            }
        });
        //将Integer类型转回基本数据类型int
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = temp[i];
        }
        return arr1;
    }

    public int[] relativeSortArray3(int[] arr1, int[] arr2) {
        int upper = 0;
        for (int x : arr1) {
            upper = Math.max(upper, x);
        }
        int[] frequency = new int[upper + 1];
        for (int x : arr1) {
            ++frequency[x];
        }
        int[] ans = new int[arr1.length];
        int index = 0;
        for (int x : arr2) {
            for (int i = 0; i < frequency[x]; ++i) {
                ans[index++] = x;
            }
            frequency[x] = 0;
        }
        for (int x = 0; x <= upper; ++x) {
            for (int i = 0; i < frequency[x]; ++i) {
                ans[index++] = x;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] arr1 = {2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19}, arr2 = {2, 1, 4, 3, 9, 6};

        Solution solution = new Solution();
        int[] list = solution.relativeSortArray(arr1, arr2);
        int[] list2 = solution.relativeSortArray2(arr1, arr2);
        int[] list3 = solution.relativeSortArray3(arr1, arr2);
        for (int i = 0; i < list.length; i++) {
            System.out.println(list[i] + " " + list2[i] + " " + list3[i]);
        }
    }
}