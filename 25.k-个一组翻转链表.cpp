/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt = 0;
        ListNode* cur = head;
        while(cur) {
            cnt++;
            cur = cur->next;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;

        while(cnt >= k) {
            cnt -= k;

            ListNode* pre = nullptr;
            ListNode* cur = p->next;    

            for(int i = 0; i < k; i++) {
                ListNode* node = cur->next;
                cur->next = pre;
                pre = cur;
                cur = node;
            }

            ListNode* nxt = p->next;
            p->next->next = cur;
            p->next = pre;
            p = nxt;
        }

        return dummy->next;
    }
};
// @lc code=end

