//
//  347_TopKFrequent.h
//  LearnC++
//
//  Created by cy on 2021/4/15.
//

#ifndef _47_TopKFrequent_h
#define _47_TopKFrequent_h

#pragma once
#include "../Base.h"

class _347_TopKFrequent_h : public BASE {
public:
    virtual void main()
    {
        vector<int> result;
        
        vector<int> nums = {1,1,1,2,2,3};
        int k = 2;
        result = topKFrequent(nums, k);
        for(int i = 0 ; i < result.size() ; i++)
        {
            cout << i << endl;
        }
    }
    
//    思想：用hash表来存储每个数字对应的出现次数，然后使用堆排序，取出频率最高的前k个数字。那么对于频率k之后的数据就不用排序，进一步提高效率。
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> arr;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            auto it = m.find(nums[i]);
            if(it != m.end())
            {
                it->second++;
            }
            m.insert(pair<int, int>(nums[i], 1));
        }
        
        for(auto& a : m)
        {
            arr.emplace_back(a.second);
        }

        heapSort(arr, arr.size());
        
        vector<int> result;
        for(int i = 0 ; i < k ; i++)
        {
            result.emplace_back(arr[i]);
        }
        
//        for (auto& x: m)
//            std::cout << x.first << ": " << x.second << std::endl;
        
        return result;
    }
    
    // 递归方式构建大根堆(len是arr的长度，index是第一个非叶子节点的下标)
    void adjust(vector<int> &arr, int len, int index)
    {
        int left = 2*index + 1; // index的左子节点
        int right = 2*index + 2;// index的右子节点
     
        int maxIdx = index;
        if(left<len && arr[left] > arr[maxIdx])     maxIdx = left;
        if(right<len && arr[right] > arr[maxIdx])     maxIdx = right;
     
        if(maxIdx != index)
        {
            swap(arr[maxIdx], arr[index]);
            adjust(arr, len, maxIdx);
        }
     
    }
     
    // 堆排序
    void heapSort(vector<int> &arr, int size)
    {
        // 构建大根堆（从最后一个非叶子节点向上）
        for(int i=size/2 - 1; i >= 0; i--)
        {
            adjust(arr, size, i);
        }
     
        // 调整大根堆
        for(int i = size - 1; i >= 1; i--)
        {
            swap(arr[0], arr[i]);           // 将当前最大的放置到数组末尾
            adjust(arr, i, 0);              // 将未完成排序的部分继续进行堆排序
        }
    }
};

#endif /* _47_TopKFrequent_h */
