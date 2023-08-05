package L23;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

class ListNode {
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

class Node implements Comparable<Node> {
    int key;
    ListNode listNode;

    public Node(int key, ListNode listNode) {
        this.key = key;
        this.listNode = listNode;
    }

    @Override
    public int compareTo(Node o) {
        return this.key - o.key;
    }
}

/**
 * 小根堆
 */
class BinaryHeap {
    private List<Node> heap;

    public BinaryHeap() {
        this.heap = new ArrayList<>();
        heap.add(null);
    }

    public boolean isEmpty() {
        return heap.size() == 1;
    }

    public Node getMin() {
        return heap.get(1);
    }


    public void insert(Node node) {
        heap.add(node);
        heapifyUp(heap.size() - 1);
    }

    public void deleteMin() {
        heap.set(1, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        heapifyDown(1);
    }

    private void heapifyUp(int p) {
        while (p > 1) {
            if (heap.get(p).key < heap.get(p / 2).key) {
                swap(p, p / 2);
                p /= 2;
            } else break;
        }
    }

    private void heapifyDown(int p) {
        int child = p * 2;
        while (child < heap.size()) {
            int other = p * 2 + 1;
            if (other < heap.size() && heap.get(other).key < heap.get(child).key)
                child = other;
            if (heap.get(p).key > heap.get(child).key) {
                swap(child, p);
                p = child;
                child = p * 2;
            } else break;
        }
    }

    private void swap(int i, int j) {
        Node temp = heap.get(i);
        heap.set(i,heap.get(j));
        heap.set(j,temp);
    }
}

public class Solution {
    private PriorityQueue<Node> queue = new PriorityQueue<>();

    public ListNode mergeKLists(ListNode[] lists) {
        for (ListNode listNode : lists) {
            if (listNode == null) continue;
            queue.add(new Node(listNode.val, listNode));
        }
        ListNode head = new ListNode();// 保护点
        ListNode tail = head;

        while (!queue.isEmpty()) {
            Node node = queue.poll();
            tail.next = node.listNode;
            tail = tail.next;
            ListNode next = node.listNode.next;
            if (next != null) {
                queue.add(new Node(next.val, next));
            }

        }
        return head.next;
    }

    private BinaryHeap q = new BinaryHeap();

    public ListNode mergeKLists2(ListNode[] lists) {
        for (ListNode listNode : lists) {
            if (listNode == null) continue;
            q.insert(new Node(listNode.val, listNode));
        }

        ListNode head = new ListNode();// 保护点
        ListNode tail = head;

        while (!q.isEmpty()) {
            Node node = q.getMin();
            q.deleteMin();
            tail.next = node.listNode;
            tail = tail.next;
            ListNode next = node.listNode.next;
            if (next != null) {
                q.insert(new Node(next.val, next));
            }

        }
        return head.next;
    }
}
