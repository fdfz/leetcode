/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l, *pre = nullptr, *head = nullptr;
        bool carry = false;
        bool first = true;
        while (l1 != nullptr || l2 != nullptr || carry) {

            int sum = carry;
            if (l1) {
                sum += l1->val;
            }
            if (l2) {
                sum += l2->val;
            }
            l = new ListNode(sum % 10);
            if (pre)
                pre->next = l;
            if (first) {
                head = l;
                first = false;
            }
            carry = sum >= 10;
            pre = l;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }
        return head;
    }
};