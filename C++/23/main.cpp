#include <iostream>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct Node {
    int key;
    ListNode *listNode;

    Node(int key, ListNode *listNode) : key(key), listNode(listNode) {}
};

/**
 * 系统自带priority_queue默认是大根堆 通过反着重载小于号 欺骗库，通过此方法将其改进为小根堆
 * @param a
 * @param b
 * @return
 */
bool operator<(const Node &a, const Node &b) {
    return a.key > b.key;
}

class Solution {
private:
    priority_queue<Node> q;
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for (ListNode *listNode: lists) {
            if (listNode == nullptr)continue;
            q.push(Node(listNode->val, listNode));
        }
        ListNode head;// 保护点
        ListNode *tail = &head;
        while (!q.empty()) {
            Node node = q.top();
            q.pop();
            tail->next = node.listNode;
            tail = tail->next;
            ListNode *next = node.listNode->next;
            if (next != nullptr) {
                q.push(Node(next->val, next));
            }

        }
        return head.next;
    }
};

class BinaryHeap {
public:
    BinaryHeap() {
        // 从1开始存 0位置浪费
        heap.push_back(Node(0, nullptr));
    }

    bool empty() {
        return heap.size() == 1;
    }

    Node getMin() { return heap[1]; }

    void insert(const Node &node) {
        heap.push_back(node);
        heapifyUp(heap.size() - 1);
    }

    void deleteMin() {
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        heapifyDown(1);
    }

private:
    void heapifyUp(int p) {
        while (p > 1) {
            // 小根堆 顶上是最小的
            if (heap[p].key < heap[p / 2].key) {
                swap(heap[p], heap[p / 2]);
                p /= 2;
            } else break;
        }
    }

    void heapifyDown(int p) {
        int child = p * 2; // 要换的孩子
        while (child < heap.size()) {
            int other = p * 2 + 1;// 另一个孩子
            if (other < heap.size() && heap[other].key < heap[child].key)
                child = other;
            if (heap[p].key > heap[child].key) {
                swap(heap[child], heap[p]);
                p = child;
                child = p*2;
            } else break;
        }
    }

    vector<Node> heap;
};

class Solution2 {
private:
    BinaryHeap q;
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        for (ListNode *listNode: lists) {
            if (listNode == nullptr)continue;
            q.insert(Node(listNode->val, listNode));
        }
        ListNode head;// 保护点
        ListNode *tail = &head;
        while (!q.empty()) {
            Node node = q.getMin();
            q.deleteMin();
            tail->next = node.listNode;
            tail = tail->next;
            ListNode *next = node.listNode->next;
            if (next != nullptr) {
                q.insert(Node(next->val, next));
            }

        }
        return head.next;
    }
};

int main() {
    return 0;
}
