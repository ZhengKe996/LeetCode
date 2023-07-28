#include <iostream>
#include <stack>

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
    /**
     * 使用栈的方式
     * @param head
     * @param k
     * @return
     */
    ListNode *reverseKGroup(ListNode *head, int k) {
        stack<ListNode *> stk;
        ListNode *res = new ListNode;
        ListNode *p = res, *q;
        int i;
        while (head) {
            for (i = 0; head && i < k; i++) { // k个一组进栈
                stk.push(head);
                head = head->next;
            }

            if (i != k)break;//不成一组跳出

            while (!stk.empty()) {//逆序出栈
                p->next = stk.top();
                p = stk.top();
                stk.pop();
            }
            q = head;
        }
        p->next = q;//接上余下的点
        return res->next;
    }
};

int main() {

    return 0;
}
