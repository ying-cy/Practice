//
//  05_LongestPalindrome.h
//  LearnC++
//
//  Created by cy on 2021/5/29.
//

#ifndef _5_LongestPalindrome_h
#define _5_LongestPalindrome_h

#pragma once
#include "../Base.h"

class _05_LongestPalindrome_h : public BASE {
public:
//    5. 最长回文子串: 给你一个字符串 s，找到 s 中最长的回文子串。
    virtual void main()
    {
        string s = "baabad";
        string r = longestPalindrome(s);
        cout << "LongestStr: " << r << endl;
    }
    
    // 最长回文子串是动态规划中的经典题目
    // 动态规划的解题步骤：
    // 1、dp[i][j] 表示 s[i..j] 是否是回文串  （这是一个状态转移方程，记录的是状态）
    // 2、公式: dp[i, j] = dp[i+1, j-1] + dp[j] ,dp[i] = dp[j]
    // 3、边界条件：字符串长度为1的时候，一定是回文子串；长度为2的时候，如果字符相等，则为回文子串
    string longestPalindrome(string s) {
        int len = (int)s.size();
        if(len < 2) return s;
        
        int maxlen = 1;
        int begin = 0;
//        dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<bool>> dp(len, vector<bool>(len));

        // 初始化长度为1的部分,都是回文串
        for(int i = 0 ; i < len ; i++)
        {
            dp[i][i] = true;
        }
        
//        先枚举子串长度，然后枚举左边界。
//        由子串长度和左边界确定右边界。
        for(int L = 2 ; L <= len ; L++) {
            for(int left = 0 ; left < len ; left++) {
                int right = left + L - 1;
                if(right >= len)
                    break;
                
//                核心部分
                if(s[left] != s[right]) {
                    dp[left][right] = false;
                }else {
                    if(right - left < 3) {
                        dp[left][right] = true;
                    }else {
                        dp[left][right] = dp[left+1][right-1];
                    }
                }
                
//                记录回文字符的最大长度、起始位置
                if(dp[left][right] && right - left + 1 > maxlen) {
                    maxlen = right - left + 1;
                    begin = left;
                }
            }
        }
        return s.substr(begin, maxlen);
    }
};

#endif /* _5_LongestPalindrome_h */
