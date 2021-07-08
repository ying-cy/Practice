//
//  03_LengthOfLongestSubstring.h
//  LearnC++
//
//  Created by cy on 2021/4/16.
//

#ifndef _3_LengthOfLongestSubstring_h
#define _3_LengthOfLongestSubstring_h

#pragma once
#include "../Base.h"

class _03_LengthOfLongestSubstring_h : public BASE {
public:
    virtual void main()
    {
        string s = "pwwkew";
        int n;
        
        n = lengthOfLongestSubstring(s);
        cout << "Length Of Longest Substring: " << n;

    }
    
//思路：把字符一个个放入hash表中，如果有重复的话，就把重复字符以及其前面的移除
//    不对❌，上述思路是错误的，错误的点在于：哈希表是无序的，你存进去的字符并不是按照顺序依次摆好的，因为有了哈希函数的存在，它相当于是映射进去的函数，所以你在删除的时候是不可以按照顺序删除的，这是不对的。
//  ✅ 定义一个指针，指向数组的第一个字符。
//     将字符串中的字符插入hash表中，在插入的时候，如果有重复的数字，那么利用指针删除hash表中数组中这个重复字符之前的所有字符。
    int lengthOfLongestSubstring(string s)
    {
        if(s.size() == 0) return 0;
        
        int maxSize = 0;
        int left = 0;
        unordered_set<char> m;
        
        for(int i = 0 ; i < s.size() ; i++)
        {
            while(m.find(s[i]) != m.end())
            {
//              注意你删除的时候删的是s[left]，而不是s[i]。
                m.erase(s[left]);
                left++;
            }
            maxSize = max(maxSize, i-left+1);
            m.insert(s[i]);
        }
        
        return maxSize;
    }
};

#endif /* _3_LengthOfLongestSubstring_h */
