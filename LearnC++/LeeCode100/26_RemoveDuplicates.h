//
//  RemoveDuplicates.h
//  LearnC++
//
//  Created by cy on 2021/4/20.
//

#ifndef RemoveDuplicates_h
#define RemoveDuplicates_h

#pragma once
#include "../Base.h"

//题目: 删除排序数组中的重复项
//给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。
//
//不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。

//输入：nums = [0,0,1,1,1,2,2,3,3,4]
//输出：5, nums = [0,1,2,3,4]
//解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。



class _RemoveDuplicates_h : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = {1,1};
        int len = removeDuplicates(nums);
        cout << "len:" << len << endl;
        for(int i = 0; i < len ; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    
//    思路：用到两个指针。一个指针在前，一个指针在后。
//    1、如果两个指针相等，那么后面的指针一直向后移动
//    2、如果两个指针不相等，那么后面的指针所指向和值替换为first指针指向的下一个值，first指针后移一位。
//    返回first + 1，为新的不重复的数组的长度
    
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1) return 1;
        
        int first = 0;
        int second = 1;
        
        while (second < nums.size())
        {
           if(nums[first] != nums[second])
           {
               nums[++first] = nums[second];
           }
            second++;
        }
        return first + 1;
    }
};

#endif /* RemoveDuplicates_h */
