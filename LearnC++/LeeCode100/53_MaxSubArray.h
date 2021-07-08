//
//  53_MaxSubArray.h
//  LearnC++
//
//  Created by cy on 2021/5/12.
//

#ifndef _3_MaxSubArray_h
#define _3_MaxSubArray_h

#pragma once
#include "../Base.h"

//53. 最大子序和
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。

// 动态规划，dp[i] 表示的是，到第i个数字的最大子序列和是多少。
// dp[i] = max{dp[i-1]+nums[i], nums[i]}

class _53_MaxSubArray_h : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
        int r = maxSubArray(nums);
        cout << "maxR: " << r << endl;
    }
    
    int maxSubArray(vector<int>& nums) {
        int maxR = nums[0];
        int r = nums[0];
        for(int i = 1 ; i < nums.size() ; i++)
        {
            maxR = max(maxR + nums[i], nums[i]);
            r = max(r, maxR);
        }
        return r;
    }
};

#endif /* _3_MaxSubArray_h */
