/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() <= 1)
            return intervals;
        
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back({intervals[0][0], intervals[0][1]});

        for(int i = 1; i < intervals.size(); i++) {
            if(res.back()[1] < intervals[i][0]) {
                res.push_back({intervals[i][0], intervals[i][1]});
            }
            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }

        return res;
    }
};
// @lc code=end

