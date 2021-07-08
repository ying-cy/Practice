//
//  14_LongestCommonPrefix.h
//  LearnC++
//
//  Created by cy on 2021/5/7.
//

#ifndef _4_LongestCommonPrefix_h
#define _4_LongestCommonPrefix_h

#pragma once
#include "../Base.h"

//14. 最长公共前缀
//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。

//解题思路：由于是前缀，先把第一个字符串中的所有字符存进哈希表中，然后再把第二个字符中的字符和第一个中的进行比较，删除不相等的字符。

class _14_LongestCommonPrefix_h : public BASE {
public:
    virtual void main()
    {
        string strCommon;
        vector<string> strs = {"flower","flow","flight"};
        strCommon = longestCommonPrefix(strs);
        cout << strCommon << endl;
    }
    
    string longestCommonPrefix(vector<string>& strs)
    {
        string s;
        for(int i = 0 ; i < strs.size() ; i++){
            cout << strs[i] << endl;
            unordered_set<char> m;
        }
        
        return s;
    }
};

#endif /* _4_LongestCommonPrefix_h */
