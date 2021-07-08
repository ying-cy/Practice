//
//  20_IsValid.h
//  LearnC++
//
//  Created by cy on 2021/5/6.
//

#ifndef _0_IsValid_h
#define _0_IsValid_h

#pragma once
#include "../Base.h"

//20. 有效的括号
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
//
//有效字符串需满足：
//- 左括号必须用相同类型的右括号闭合。
//- 左括号必须以正确的顺序闭合。

//用到 “hash表” 和 “栈”。
//将字符串一个个的入栈，如果遇见匹配的就把另一个出栈。


class _IsValid_h : public BASE {
public:
    virtual void main()
    {
        string s = "()";
        bool result = isValid(s);
        cout << "bool: " << (int)result << endl;
    }
    
    bool isValid(string s) {
        int num = s.size();
        if(num % 2 == 1)
            return false;
            
        unordered_map<char, char> m =
        {
            {')', '('},
            {']', '['},
            {'{', '}'}
        };
        
        stack<char> stk;
        
        // 遍历字符串中的字符
        for (char ch: s)
        {
            // unordered_map中存放的是右边的括号。如果当前的字符是右边的括号，那么弹栈，否则压栈。
            if (m.count(ch)) {
                //循环结束：栈为空，或者栈顶元素不等于该字符，匹配失败。
                if (stk.empty() || stk.top() != m[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

#endif /* _0_IsValid_h */
