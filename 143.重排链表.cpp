/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

// @lc code=start
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
        ListNode* fast = head, *slow = head;
        while(fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* pre = nullptr;
        ListNode* cur = slow->next;
        slow->next = nullptr;

        while(cur) {
            ListNode* n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }

        ListNode* l1 = head;
        ListNode* l2 = pre;
        while(l2) {
            ListNode* l1n = l1->next;
            ListNode* l2n = l2->next;
            l1->next = l2;
            l2->next = l1n;
            l1 = l1n;
            l2 = l2n;
        }
    }
};
// @lc code=end

