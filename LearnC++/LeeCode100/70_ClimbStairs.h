//
//  70_ClimbStairs.h
//  LearnC++
//
//  Created by cy on 2021/5/12.
//

#ifndef _0_ClimbStairs_h
#define _0_ClimbStairs_h

#pragma once
#include "../Base.h"

//70. 爬楼梯
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//注意：给定 n 是一个正整数。

//动态规划，dp[i]表示的是到达第n阶楼梯的方法总数
//dp[i] = dp[i-1] + dp[i-2]
//dp[1] = 1;dp[0] = 1;
//dp[2] = dp[1] + dp[0];
//因为最终的数字只和前两个数字有关，因此用到了“滚动数组”的思想。我只需要相邻三个数字的值，因此每向前走一步，最左边的数字可以被扔掉，

class _70_ClimbStairs_h : public BASE {
public:
    virtual void main()
    {
        int n = 3;
        int r = climbStairs(n);
        cout << "r: " << r;
    }
    
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for(int i = 1 ; i <= n ; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }
        return r;
    }
};

#endif /* _0_ClimbStairs_h */
