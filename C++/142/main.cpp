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
     * 相遇时，有2(1+p)=l+p+k*r，其中k为整数（套的圈数）
     * 即l=k*r-p=(k -1)*r+(r- p)
     * 含义：从 head 走到 st，等于从 meet 走到 st，然后再绕几圈
     * 此时开始让慢指针与 head 同时移动，必定在环的起始点相遇
     * @param head
     * @return
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) return nullptr;
            fast = fast->next->next;
            // 两个指针响应证明有环
            if (fast == slow) {
                ListNode *pre = head;
                while (pre != slow) {
                    pre = pre->next;
                    slow = slow->next;
                }
                return pre;
            }
        }
        return nullptr;
    }
};

int main() {
    return 0;
}
