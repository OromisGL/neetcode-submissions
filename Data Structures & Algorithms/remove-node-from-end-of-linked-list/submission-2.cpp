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

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* slow = head;
        ListNode* fast = head;
        int steps = 0;

        while (fast) {
            fast = fast->next;
            steps++;
        }
        int rm = steps - n;
        if (rm == 0) {
            head = slow->next;
            return head;
        }
        while (slow && rm > 1) {
            slow = slow->next;
            rm--;
        }

        slow->next = slow->next->next;

        return head;
    }
};
