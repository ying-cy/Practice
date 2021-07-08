#ifndef _5_ReplaceSpaces_h
#define _5_ReplaceSpaces_h

#include "../Base.h"

//题目:05 替换字符串中的空格

//解法思路
//1.两个指针，分别指向原有的字符串最末端以及添加空格后的字符串最末端。
//2.指针二不断复制指针一的指向内容，直到指针一遇见空格为止，
//3.此时指针二插入三个字符来替换空格，指针二向前移动三个，指针一向前移动一个
//4.不断重复第二步和第三步，直到两个指针指向同一个地方结束。
//返回现有的字符串

//遇到的问题：
//1、单引号和双引号的区别：单引号代表字符，双引号代表字符串。
//2、如何计算字符数组的长度？扫描存储字符的数组，直到遇到"/0"的终止符。

class _5_ReplaceSpaces : public BASE {
public:
    virtual void main()
    {
        char str[20] = { "we are happy." };
        ReplaceStr(str, 20);
    }

    void ReplaceStr(char str[], int length)
    {
        int originalLength = 0;
        int addBlankLength = 0;
        int blankNum = 0;
        int i = 0;
        if (str == nullptr || length <= 0)
            return;
    
        while (str[i] != '\0') {
            ++originalLength;
            if (str[i] == ' ')
                ++blankNum;
            ++i;
        }
    
        addBlankLength = originalLength + blankNum * 2;
        if (addBlankLength > length)
            return;
    
        //算出了字符数组的长度，以及替换字符后的字符数组的长度。它们两个应该是常量，所以要想用指针，得重新创建一个变量
        int indexOfOriginal = originalLength;
        int indexOfAdd = addBlankLength;
    
        while (indexOfOriginal != indexOfAdd)
        {
            if (str[indexOfOriginal] != ' ')
            {
                str[indexOfAdd] = str[indexOfOriginal];
                indexOfOriginal--;
                indexOfAdd--;
            }
            else {
                str[indexOfAdd--] = '0';
                str[indexOfAdd--] = '2';
                str[indexOfAdd--] = '%';
                indexOfOriginal--;
            }
        }
    
        for (int i = 0; i < addBlankLength; i++)
        {
            cout << str[i];
        }
        
    }
};

#endif /* _5_ReplaceSpaces_h */
