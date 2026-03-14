/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> result;

    bool isValid(vector<string>& m, int row, int col) {
        // 列有效
        for(int i = 0; i < row; i++) {
            if(m[i][col] == 'Q')
                return false;
        }

        // 正对角线有效
        for(int i = row - 1, j = col - 1; i >= 0&&j >= 0; i--, j--) {
            if(m[i][j] == 'Q')
                return false;
        }

        // 反对角线有效
        for(int i = row - 1, j = col + 1; i >= 0&&j < m.size(); i--, j++) {
            if(m[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void backtrace(int row, vector<string>& m)
    {
        if(row == m.size()) {
            result.push_back(m);
            return;
        }
        
        for(int col = 0; col < m.size(); col++) {
            if(isValid(m, row, col)) {
                m[row][col] = 'Q';
                backtrace(row + 1, m);
                m[row][col] = '.';
            }
        } 
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans(n, string(n, '.'));
        
        backtrace(0, ans);

        return result;
    }
};
// @lc code=end

