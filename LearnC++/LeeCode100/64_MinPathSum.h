//
//  64_MinPathSum.h
//  LearnC++
//
//  Created by cy on 2021/5/13.
//

#ifndef _4_MinPathSum_h
#define _4_MinPathSum_h

#pragma once
#include "../Base.h"

class _64_MinPathSum_h : public BASE {
public:
//    64. 最小路径和
//    给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
//    说明：每次只能向下或者向右移动一步。
//
//    思路：动态规划。dp[i][j] = min(dp[i-1][j], dp[i][j-1])
//    处理一下边界
    
    virtual void main()
    {
        int m, n;
        vector<vector<int>> grid = {
//            {1,3,1},
//            {1,5,1},
//            {4,2,1}
            {1,2,3},
            {4,5,6}
        };
        int r = minPathSum(grid);
        cout << r;
    }
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        if (m == 0 || n == 0) {
            return 0;
        }
        
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(i == 0 && j==0)
                {
                    grid[i][j] = grid[0][0];
                }
                else if(i == 0){
                    grid[i][j] = grid[i][j-1] + grid[i][j];
                }else if(j == 0){
                    grid[i][j] = grid[i-1][j] + grid[i][j];
                }else{
                    grid[i][j] = min(grid[i-1][j] + grid[i][j], grid[i][j-1] + grid[i][j]);
                }
            }
                
        }
        return grid[m-1][n-1];
    }

};

#endif /* _4_MinPathSum_h */
