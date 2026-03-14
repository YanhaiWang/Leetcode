/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(n < 2)
            return res;

        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1, k = n - 1;
            while(j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while(j < k && nums[j] == nums[j + 1])
                        j++;
                    while(j < k && nums[k] == nums[k - 1])
                        k--;
                    j++;
                    k--;
                }

                if(sum < 0) {
                    j++;
                }

                if(sum > 0) {
                    k--;
                }
            }
        }

        return res;
    }
};
// @lc code=end

