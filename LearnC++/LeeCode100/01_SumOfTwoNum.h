//
//  SumOfTwoNum.h
//  LearnC++
//
//  Created by cy on 2021/3/26.
//

#ifndef SumOfTwoNum_h
#define SumOfTwoNum_h

#pragma once
#include "../Base.h"

// [1. 两数之和]
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
//
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

class _01_SumOfTwoNum_h : public BASE {
public:
    virtual void main()
    {
        vector<int> arr = {2, 7, 11, 15};
        int target = 9;
        vector<int> result = twoSum(arr, target);
        
    }
    
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> res;
        for(int i = 0; i < nums.size() ; i++) {
            for(int j = i + 1 ; j < nums.size() ; j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
//        vector<int> result;
//
//        vector<int>::iterator it;
//        for(it = nums.begin() ; it < nums.end() ; it++)
//        {
//            vector<int>::iterator it2;
//            for (it2 = it+1 ; it2 < nums.end() ; it2++)
//            {
//                if(*it + *it2 == target)
//                {
//                    result.push_back(int(&*it - &nums[0]));
//                    result.push_back(int(&*it2 - &nums[0]));
//                }
//
//            }
//        }
//
//        return result;
//
        
    }
};

#endif /* SumOfTwoNum_h */

