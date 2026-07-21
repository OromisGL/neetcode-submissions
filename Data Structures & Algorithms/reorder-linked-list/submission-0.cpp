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
    void reorderList(ListNode* head) {
        if (!head) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* half2 = slow->next;
        slow->next = nullptr;

        ListNode* curr = half2;
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* tempnext = curr->next;
            curr->next = prev;

            prev = curr;
            curr = tempnext;
        }

        while (prev) {
            ListNode* tmp1 = head->next;
            ListNode* tmp2 = prev->next;

            head->next = prev;
            prev->next = tmp1;

            head = tmp1;
            prev = tmp2;
        }

    }
};
