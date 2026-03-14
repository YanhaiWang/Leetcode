/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        
        for(int i = 1; i < n; i++) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(buy1 + prices[i], sell1);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(buy2 + prices[i], sell2);
        }

        return sell2;
    }
};
// @lc code=end

