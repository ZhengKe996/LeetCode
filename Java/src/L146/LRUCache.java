package L146;

import java.util.HashMap;

public class LRUCache {
    private class Node {
        int key;
        int value;
        Node pre;
        Node next;

        public Node() {
        }

        public Node(int key, int value, Node pre, Node next) {
            this.key = key;
            this.value = value;
            this.pre = pre;
            this.next = next;
        }
    }

    private HashMap<Integer, Node> h = new HashMap<Integer, Node>();

    private Node head;// 头节点
    private Node tail;// 尾节点
    private int capacity; // 容量

    // 双向链表删除节点
    private void remove(Node node) {
        node.pre.next = node.next;
        node.next.pre = node.pre;
    }

    // 双向链表插入节点
    void insert(Node p, Node node) {
        p.next.pre = node;
        node.next = p.next;
        p.next = node;
        node.pre = p;
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.pre = head;
    }

    public int get(int key) {
        Node node = h.get(key);
        if (node == null) return -1;

        remove(node);
        insert(head, node);
        return node.value;
    }

    public void put(int key, int value) {
        Node node = h.get(key);
        if (node == null) {
            Node node1 = new Node();
            node1.key = key;
            node1.value = value;
            h.put(key, node1);
            insert(head, node1);

            // 超容量的情况
            if (h.size() > capacity) {
                //TODO: 删除最旧的
                h.remove(tail.pre.key);
                remove(tail.pre);
            }
        } else {
            // TODO: 更新
            Node node1 = h.get(key);
            node1.value = value;
            remove(node1);
            insert(head, node1);
        }
    }
}
