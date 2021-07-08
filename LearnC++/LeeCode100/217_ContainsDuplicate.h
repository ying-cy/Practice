//
//  217_ContainsDuplicate.h
//  LearnC++
//
//  Created by cy on 2021/4/20.
//

#ifndef _17_ContainsDuplicate_h
#define _17_ContainsDuplicate_h

#pragma once
#include "../Base.h"

//217. 存在重复元素
//给定一个整数数组，判断是否存在重复元素。
//
//如果存在一值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false 。

class _217_ContainsDuplicate_h : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = { 1,1,1,3,3,4,3,2,4,2 };
        bool result = containsDuplicate(nums);
        if(result == true)
            cout << "result: true" << endl;
        else
            cout << "result: false" << endl;
    }
    
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> m;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(m.find(nums[i]) != m.end())
            {
                return true;
            }
            m.insert(nums[i]);
        }
        return false;
    }
};

#endif /* _17_ContainsDuplicate_h */
