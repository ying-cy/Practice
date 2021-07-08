//
//  121_MaxProfit.h
//  LearnC++
//
//  Created by cy on 2021/5/13.
//

#ifndef _21_MaxProfit_h
#define _21_MaxProfit_h

#pragma once
#include "../Base.h"
//121. 买卖股票的最佳时机
//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0。

//这个问题说白了就是：求两个数之间的最大差值，并且第一个数要小于第二个数
//动态规划：dp[i]表示的是到第i天能获取到的最大利润，那么可以选择的是今天卖还是不卖。
//dp[i] = max(dp[i-1], prices[i]-minPrices)

class _121_MaxProfit_h : public BASE {
public:
    virtual void main()
    {
        vector<int> prices = {7,1,5,3,6,4};
        int m = maxProfit(prices);
        cout << m <<endl;
    }

    int maxProfit(vector<int>& prices) {
        int minPrices = prices[0];
        
        int s = prices.size();
        if(s == 0) return 0;
        vector<int> dp(s, 0);
        
        for(int i = 1 ; i < s ; i++)
        {
            minPrices = min(minPrices, prices[i]);
            dp[i] = max(dp[i-1], prices[i] - minPrices);
        }
        
        return dp[s-1];
    }
};

#endif /* _21_MaxProfit_h */
