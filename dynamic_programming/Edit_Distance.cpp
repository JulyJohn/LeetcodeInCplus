//
// Created by yzjhh on 2019/3/18.
//

/**
 *
 * 72. Edit Distance
 *
 * Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 *
 * You have the following 3 operations permitted on a word:
 * Insert a character
 * Delete a character
 * Replace a character
 *
 * 题目描述：求通过删除、替换、插入操作使得两个字符串相等的最小操作数。
 *
 * Note：
    1、从i-1,j 为T1增加一个字符，获得i，j，这样编辑距离本身就需要+1
    2、同理，从i，j-1过来，编辑距离必须+1。
    3、从i-1，j-1位置变换过来，那么这个时后，如果T1在i的取值和T2在j的取值一样，那么这个变换，编辑距离不变，如果不一样，那么就需要做替换操作，那么必须+1.

 Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 *
 * */

class Solution {
public:
    // init: dp[i][0] = word1[i]; dp[0][j] = word2[j];
    // word1[i] == word2[j], dp[i][j] = dp[i-1][j-1]
    // word1[i] == word2[j], dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int >> dp(m+1, vector<int >(n+1, 0));
        for(int i = 1; i <= m; ++i){
            dp[i][0] = i;
        }
        for(int j = 1; j <= n; ++j){
            dp[0][j] = j;
        }
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }
        }
        return dp[m][n];
    }
};