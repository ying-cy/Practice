//
//  11_maxArea.h
//  LearnC++
//
//  Created by cy on 2021/7/9.
//

#ifndef _1_maxArea_h
#define _1_maxArea_h

#pragma once
#include "../Base.h"

class _11_maxArea_h : public BASE {
public:
    virtual void main()
    {
        vector<int> height = {1,1};
        int r = maxArea(height);
        cout << r;
    }
    
    // 使用快慢指针，指向一前一后
//    1. 哪边的值比较小就挪哪边
//    2. 记录最大的值
    int maxArea(vector<int>& height) {
        int size = (int)height.size();
        int start = 0;
        int end = size - 1;
        int s = 0, maxS = 0;

        while(start != end) {
            s = (end-start) * min(height[start], height[end]);
            maxS = max(s, maxS);

            if(height[start] < height[end]) {
                start++;
            } else {
                end--;
            }
        }
        return maxS;
    }
};


#endif /* _1_maxArea_h */
