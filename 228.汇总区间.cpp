/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */

// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if(n == 0)
            return res;

        int start = nums[0];
        string str = "";
        for(int i = 1; i <= n; i++) {
            if(i == n || nums[i] != nums[i - 1] + 1) {
                if(start == nums[i - 1])
                    res.push_back(to_string(start));
                else
                    res.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
            
                if(i < n) {
                    start = nums[i];
                }    
            }
        }
        return res;
    }
};
// @lc code=end

