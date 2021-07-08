//
//  62_UniquePaths.h
//  LearnC++
//
//  Created by cy on 2021/5/13.
//

#ifndef _2_UniquePaths_h
#define _2_UniquePaths_h

#pragma once
#include "../Base.h"

class _62_UniquePaths_h : public BASE {
public:
//    62. 不同路径
//    一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
//    机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
//    问总共有多少条不同的路径？
    virtual void main()
    {
        int m = 3, n = 2;
        int r = uniquePaths(m, n);
        cout << r <<endl;
    }
    
    int uniquePaths(int m, int n) {
      // dp[i][j]表示的是到达在（i，j）这个位置的时候，一共有多少种不同的路径。那么如果要到达这个地方，只可能来自于它的上面或者是左边。
      // dp[i][j] = dp[i-1][j] + dp[i][j-1]
      // 处理边缘操作
//        优化：我们不需要二维数组，我们只需要相邻的两个数
        // 二维数组的初始化
        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(i == 0 || j == 0){
                    dp[i][j] = 1;
                }else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};


#endif /* _2_UniquePaths_h */
