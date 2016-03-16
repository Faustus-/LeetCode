//
//  72_Edit_Distance.h
//  leetCode
//
//  Created by PengYan on 16/3/16.
//  Copyright © 2016年 PengYan. All rights reserved.
//
//  Description
/*  Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 
 You have the following 3 operations permitted on a word:
 
 a) Insert a character
 b) Delete a character
 c) Replace a character
*/


#ifndef _2_Edit_Distance_h
#define _2_Edit_Distance_h


#endif /* _2_Edit_Distance_h */

#include <vector>

using namespace std;

class Solution {
    // dp, similar to LCS
public:
    int minDistance(string word1, string word2) {
        vector<vector<int> > dp(word1.length() + 1, vector<int> (word2.length() + 1, 0));
        for (int i = 1; i <= word1.length(); i++)
            dp[i][0] = i;
        for (int i = 1; i <= word2.length(); i++)
            dp[0][i] = i;
        for (int i = 1; i <= word1.length(); i++) {
            for (int j = 1; j <= word2.length(); j++) {
                int replace_step = 0;
                if (word1[i - 1] == word2[j - 1])
                    replace_step = dp[i - 1][j - 1];
                else
                    replace_step = dp[i - 1][j - 1] + 1;
                replace_step = min(replace_step, dp[i - 1][j] + 1);
                dp[i][j] = min(replace_step, dp[i][j - 1] + 1);
            }
        }
        return dp[word1.length()][word2.length()];
    }  
};