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
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* curr = new ListNode();
        ListNode* merge = curr;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if (l1) {
            curr->next = l1;
        } else if (l2) {
            curr->next = l2;
        }

        return merge->next;
    }

    ListNode* solve(vector<ListNode*> lists, int left, int right) {
        if (left == right) return lists[left];
        int mid = left + (right - left) / 2;
        ListNode* l1 = solve(lists, left, mid);
        ListNode* l2 = solve(lists, mid + 1, right);

        return merge(l1, l2);
     }


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (n == 0 || (n == 1 && !lists[0])) return {};
        if (n == 1 && lists[0]) return lists[0];

        return solve(lists, 0, n - 1);
    }
};
