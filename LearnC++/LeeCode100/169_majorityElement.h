//
//  169_majorityElement.h
//  LearnC++
//
//  Created by cy on 2021/7/7.
//

#ifndef _69_majorityElement_h
#define _69_majorityElement_h

#pragma once
#include "../Base.h"

class _169_majorityElement_h : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = {2,2,1,2,2};
        cout << "res01: " << majorityElement01(nums) << endl;
        cout << "res02: " << majorityElement02(nums) << endl;
        cout << "res03: " << majorityElement03(nums) << endl;
    }
    
    // 掌握三种解法：
    
    // 方法一：哈希表
    // 思路：将数组中出现的数字和出现次数用哈希表存储起来，然后遍历哈希表，找出出现次数最多的那个。
    // 时间复杂度：O(n)   空间复杂度：O(n)
    int majorityElement01(vector<int>& nums) {
        int majority = 0, frequency = 0;
        unordered_map<int, int> count;
        for(int num : nums) {
            ++count[num];
            if(count[num] > frequency) {
                frequency = count[num];
                majority = num;
            }
        }
        return majority;
    }
    
    // 方法二：排序
    // 思路：先排序，然后返回中间的数字。（因为题目中假设：数组是非空的，并且给定的数组总是存在多数元素。）
    // 时间复杂度：O(nlogn)   空间复杂度：O(n) 因为使用了语言自带的排序算法
    int majorityElement02(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
    
    // 方法三：投票算法
    // 思路：遇到相同的数，就投一票，遇到不同的数，就减一票，最后还存在票的数就是众数
    // 步骤：
    // 1. 维护一个候选众数 candidate 和它出现的次数 count。初始时 candidate 可以为任意值，count 为 0；
    // 2. 遍历数组 nums 中的所有元素，对于每个元素 x，在判断 x 之前，如果 count 的值为 0，我们先将 x 的值赋予 candidate，随后我们判断 x：
//        - 如果 x 与 candidate 相等，那么计数器 count 的值增加 1；
//        - 如果 x 与 candidate 不等，那么计数器 count 的值减少 1。
//     3. 在遍历完成后，candidate 即为整个数组的众数。
    int majorityElement03(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int num : nums) {
            if(count == 0) candidate = num;
            
            if(num == candidate) ++count;
            else --count;
        }
        return candidate;
    }
};

#endif /* _69_majorityElement_h */
