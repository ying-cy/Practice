//
//  300_LengthOfLIS.h
//  LearnC++
//
//  Created by cy on 2021/5/17.
//

#ifndef _00_LengthOfLIS_h
#define _00_LengthOfLIS_h

#pragma once
#include "../Base.h"

//300. 最长递增子序列
//给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
//子序列是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。
//例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。


class _300_LengthOfLIS_h : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = {10,9,2,5,3,7,101,18};
        int num = lengthOfLIS(nums);
        cout << num << endl;
    }
    
//    动态规划：dp[i]表示的是：考虑前i个元素，以第i个数字结尾的最长上升子序列的长度。（注意它表示的是长度）
//    dp[i] = max{dp[j]} + 1，（0 <= j < i 且 nums[j] < nums[i]）
//    dp[j] 表示的是nums[0...j] 中以nums[j]结尾的最长上升子序列。
//    参考：https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
//
//    nums = [10,9,2,5,3,7,101,18]
//    输出：4
//    解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
    int lengthOfLIS(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 0) {
            return 0;
        }
        
        vector<int> dp(n, 0);
        for(int i = 0 ; i < n ; i++){
            dp[i] = 1;
//          在dp已经遍历过的数组里找比nums[i]小的数字，
            for(int j = 0 ; j < i ; j++)
            {
                if(nums[j] < nums[i])
                {
//                  如果出现多个比它小的数字的话，取dp数最大的那个
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
//        返回dp数组中元素最大的那个值。
        return *max_element(dp.begin(), dp.end());
    }
};

#endif /* _00_LengthOfLIS_h */
