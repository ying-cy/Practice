//
//  03_RepeatedNumbersIn Array.h
//  LearnC++
//
//  Created by cy on 2021/3/16.
//


#ifndef _3_RepeatedNumbersIn_Array_h
#define _3_RepeatedNumbersIn_Array_h

#include "../Base.h"

//找出数组中重复的数字。
//
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
//
//思想：将数组中的数字放在hashmap的索引中，索引是唯一的，如果插入失败，则返回这个数字

class _3_RepeatedNumbersIn_Array : public BASE {
public:
    virtual void main()
    {
        vector<int> arr = {1,2,3,4,5,6,6,7,8};
        int num = FindRepeat(arr);
        cout << "result: " << num;
    }
    
    int FindRepeat(vector<int>& arr)
    {
        unordered_map<int, int> m;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            if(m.find(arr[i]) == m.end())
            {
                m.insert({arr[i], 1});
//                m.insert(arr[i], 1);
            }else
            {
                return arr[i];
            }
            
        }
        return -1;
    }
};


#endif /* _3_RepeatedNumbersIn_Array_h */
