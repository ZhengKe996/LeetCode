#include <iostream>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->pre = head;
    }

    int get(int key) {
        if (h.find(key) == h.end()) { // 找不到 返回-1
            return -1;
        }
        Node *node = h[key];
        remove(node);
        insert(head, node);

        return node->value;
    }

    void put(int key, int value) {
        if (h.find(key) == h.end()) {
            Node *node = new Node();
            node->key = key;
            node->value = value;
            h[key] = node;
            insert(head, node);
            // 超容量的情况,删除最旧的
            if (h.size() > capacity) {
                h.erase(tail->pre->key); // 先删key 再删节点 否则has会变
                remove(tail->pre);
            }
        } else {
            // 更新
            Node *node = h[key];
            node->value = value;
            remove(node);
            insert(head, node);
        }

    }

private:
    // 双向链表
    struct Node {
        int key;
        int value;
        Node *pre;
        Node *next;
    };

    unordered_map<int, Node *> h;
    Node *head;// 头节点
    Node *tail;// 尾节点
    int capacity; // 容量

    // 双向链表删除节点
    void remove(Node *node) {
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }

    // 双向链表插入节点
    void insert(Node *p, Node *node) {
        p->next->pre = node;
        node->next = p->next;

        p->next = node;
        node->pre = p;
    }
};

int main() {

    return 0;
}
