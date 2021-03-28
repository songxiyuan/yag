/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int i, j;
        int m = s.size();
        int n = p.size();

        /**
         * b[i + 1][j + 1]: if s[0..i] matches p[0..j]
         * if p[j] != '*'
         * b[i + 1][j + 1] = b[i][j] && s[i] == p[j]
         * if p[j] == '*', denote p[j - 1] with x,
         * then b[i + 1][j + 1] is true if any of the following is true
         * 1) "x*" repeats 0 time and matches empty: b[i + 1][j -1]
         * 2) "x*" repeats 1 time and matches x: b[i + 1][j]
         * 3) "x*" repeats >= 2 times and matches "x*x": s[i] == x && b[i][j + 1]
         * '.' matches any single character
         */
        // bool b[m + 1][n + 1]=new bool[][];
        bool **b = new bool *[m + 1];
        for (int i = 0; i < m + 1; i++)
        {
            b[i] = new bool[7];
        }
        b[0][0] = true;
        for (i = 0; i < m; i++)
        {
            b[i + 1][0] = false;
        }
        // p[0..j - 2, j - 1, j] matches empty if p[j] is '*' and p[0..j - 2] matches empty
        for (j = 0; j < n; j++)
        {
            b[0][j + 1] = j > 0 && '*' == p[j] && b[0][j - 1];
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (p[j] != '*')
                {
                    b[i + 1][j + 1] = b[i][j] && ('.' == p[j] || s[i] == p[j]);
                }
                else
                {
                    b[i + 1][j + 1] = b[i + 1][j - 1] && j > 0 || b[i + 1][j] ||
                                      b[i][j + 1] && j > 0 && ('.' == p[j - 1] || s[i] == p[j - 1]);
                }
            }
        }
        return b[m][n];
    }
};
