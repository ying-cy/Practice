//
//  Test_String.h
//  LearnC++
//
//  Created by cy on 2021/4/16.
//

#ifndef Test_String_h
#define Test_String_h

#pragma once
#include "../Base.h"

class _Test_String_h : public BASE {
public:
    virtual void main()
    {
        string strOutput = "Hello World";
        cout << "string: " << strOutput << endl;
        
        int len = strOutput.length();
        cout << "string-len: " << len << endl;
        
        const char* pszOutput = strOutput.c_str();
        cout << "char: ";
        for(int i = 0 ; i < strlen(pszOutput); i++)
        {
            
            cout << pszOutput[i];
        }
        cout << endl;
        
        string str1 = "str1";
        string str2 = "";

        //string类型可使用 compare(const string& str) 方法进行字符串比较。
        if (0 == str1.compare(str2))
        {
            cout << "str1 = str2" << endl;
        }else{
            cout << "str1 not equal with str2" << endl;
        }
        
        if (str2.empty()){
          cout << "str2 is empty." << endl;
        }else{
          cout << "str2 is not empty." << endl;
        }
        
        // 待检索的字符串
        string str = "0123456";
        // 需要检索的子串
        string strObj = "5";
     
        // 子串位于字符串中的位置
        size_t nLoc = str.find(strObj);
        // 如果检索到子串在字符串中，则打印子串的位置
        if (nLoc != string::npos)
        {
            cout << "nLoc is: " << nLoc << endl;
        }
    }
};

#endif /* Test_String_h */
