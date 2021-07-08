//
//  75_SortColors.h
//  LearnC++
//
//  Created by cy on 2021/5/19.
//

#ifndef _5_SortColors_h
#define _5_SortColors_h


#pragma once
#include "../Base.h"

class _75_SortColors_h : public BASE {
public:
//    75. 颜色分类
//    给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
//    此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
    virtual void main()
    {
        vector<int> nums = {2,0,2,1,1,0};
        sortColors(nums);
        
//      复习快排
//        int begin = 0;
//        int end = (int)nums.size();
//        quickSort(nums, begin, end);
        
        // output
        for(int i = 0 ; i < nums.size() ; i++)
        {
            cout << nums[i] << " ";
        }
    }
    
    void sortColors(vector<int>& nums) {
        int first = 0;
        int second = 0;
//        for(int x : nums){
//            if(nums[first] < )
//        }

    }
    
    // 快排
    void quickSort(vector<int>& arr, int begin, int end) {

        if(begin < end)
        {
//            指定一个标定元素
            int temp = arr[begin];
//            分别定义两个指针，指向数组的头和尾
            int i = begin;
            int j = end;
            
            while(i < j)
            {
//                先让j开始向⬅️走，直到找到比temp小的元素，就将它赋值给i指向的元素
                while(i<j && arr[j] > temp){
                    j--;
                }
                arr[i] = arr[j];
                
//              后让i开始向➡️走，直到找到比temp大的元素，将它赋值给j指向的元素。
                while(i<j && arr[i] <= temp){
                    i++;
                }
                arr[j] = arr[i];
            }
            
            arr[i] = temp;
            
            quickSort(arr,begin,i-1);
            quickSort(arr,i+1,end);
        }else{
            return;
        }
    }
};

#endif /* _5_SortColors_h */
