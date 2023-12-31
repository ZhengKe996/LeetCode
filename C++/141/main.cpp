#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * 双指针（快慢指针）
     * @param head
     * @return
     */
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            head = head->next;
            if (fast == head) return true;
        }
        return false;
    }
};

int main() {
    return 0;
}
