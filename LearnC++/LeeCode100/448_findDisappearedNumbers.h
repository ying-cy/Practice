//
//  448_findDisappearedNumbers.h
//  LearnC++
//
//  Created by cy on 2021/7/10.
//

#ifndef _48_findDisappearedNumbers_h
#define _48_findDisappearedNumbers_h

#pragma once
#include "../Base.h"

class _448_findDisappearedNumbers_h : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = {4,3,2,7,8,2,3,1};
        vector<int> result = findDisappearedNumbers(nums);
        for(auto x : result) {
            cout << x << " ";
        }
    }
    
//    1. 将数组元素对应为索引的位置加n
//    2. 遍历加n后的数组，若数组元素值小于等于n，则说明数组下标值不存在，即消失的数字
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = (int)nums.size();
        vector<int> res;
        
        if(nums.empty()) return nums;
        
        for(int i = 0 ; i < n ; i++) {
            int index = (nums[i]-1) % n;  // 比如4，对应的索引下标index为3
            nums[index] += nums.size();   // 那么数组中的nums[index]就会加n
        }
        
        for(int i = 0 ; i < n ; i++) {
            if(nums[i] <= n)              // 如果遇到了小于等于n的数字，说明下标之前没有加n，下标对应的数字不存在。
                res.push_back(i + 1);
        }
        return res;
    }
};

#endif /* _48_findDisappearedNumbers_h */
