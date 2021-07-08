//
//  283_moveZeroes.h
//  LearnC++
//
//  Created by cy on 2021/7/4.
//

#ifndef _83_moveZeroes_h
#define _83_moveZeroes_h

#pragma once
#include "../Base.h"

class _283_moveZeroes_h : public BASE {
public:
    virtual void main()
    {
        vector<int> nums = {0,1,0,3,12};
        moveZeroes(nums);
        for(auto x : nums) cout << endl << x << " ";
    }
    
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), left = 0, right = 0;
        while (right < n) {
            if (nums[right]) { // right指向的值为0，就移动到下一个。
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }

};

#endif /* _83_moveZeroes_h */
