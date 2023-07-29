#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;
        else if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

    ListNode *mergeTwoLists2(ListNode *list1, ListNode *list2) {
        ListNode *head = new ListNode(-1);
        ListNode *prev = head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }

        // 处理未被处理到的节点
        prev->next = list1 == nullptr ? list2 : list1;

        return head->next;
    }
};

int main() {
    return 0;
}
