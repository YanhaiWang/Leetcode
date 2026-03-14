/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, maxl = 0;
        unordered_map<char, int> mp;
        for(int r = 0; r < s.size(); r++) {
            while(mp.count(s[r]) > 0) {
                mp.erase(s[l]);
                l++;
            }
            mp[s[r]]++;
            maxl = max(maxl, r - l + 1);
        }

        return maxl;
    }
};
// @lc code=end

