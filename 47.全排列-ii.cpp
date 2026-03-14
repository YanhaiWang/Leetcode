/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> ans;

    void traverse(vector<int>& nums, vector<bool>& use) {
        if(ans.size() == nums.size()) {
            res.push_back(ans);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1] && !use[i - 1])
                continue;

            if(!use[i]) {
                use[i] = true;
                ans.push_back(nums[i]);
                traverse(nums, use);
                ans.pop_back();
                use[i] = false;
            }
        }
    }


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> use(nums.size(), false);
        traverse(nums, use);
        return res;
    }
};
// @lc code=end

