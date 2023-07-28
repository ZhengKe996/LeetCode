package L25;


public class Solution {
    private static class ListNode {
        int val;
        ListNode next;

        ListNode() {
        }

        ListNode(int val) {
            this.val = val;
        }

        ListNode(int val, ListNode next) {
            this.val = val;
            this.next = next;
        }
    }

    /**
     * 1. 分组（往后走k-1步，找到一组） 开头head 结尾 end
     * 2. 一组内部要反转（head-end之间反转链表）
     * 3. 更新每一组和前一组、后一组的边
     *
     * @param head
     * @param k
     * @return
     */
    public static ListNode reverseKGroup(ListNode head, int k) {
        ListNode protect = new ListNode(0, head);
        ListNode last = protect;
        while (head != null) {
            ListNode end = getEnd(head, k); // 第一步
            if (end == null) break;

            ListNode nextGroupHead = end.next;
            reverseList(head, nextGroupHead); // 第二步 反转

            last.next = end;
            head.next = nextGroupHead; // 第三步更新边界

            last = head;
            head = nextGroupHead;
        }
        return protect.next;
    }


    /**
     * @param head
     * @param k
     * @return 返回k-1步后的结点 返回null表示这一步不够走
     */
    private static ListNode getEnd(ListNode head, int k) {
        while (head != null) {
            k--;
            if (k == 0) return head;
            head = head.next;
        }
        return null;
    }

    /**
     * 反转链表
     *
     * @param head
     * @param stop
     * @return
     */
    private static void reverseList(ListNode head, ListNode stop) {
        ListNode pre = head, next = null;
        head = head.next;
        while (head != stop) {
            next = head.next;
            head.next = pre;
            pre = head;
            head = next;
        }
    }


    public static void main(String[] args) {
        ListNode node = new ListNode(1);
        ListNode pre = node;
        for (int i = 2; i <= 5; i++) {
            ListNode cur = new ListNode(i);
            pre.next = cur;
            pre = cur;
        }
        System.out.println(node.val + " " + node.next.val + " " + node.next.next.val + " " + node.next.next.next.val + " " + node.next.next.next.next.val);

    }
}
