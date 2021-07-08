//
//  21_MergeTwoLists.h
//  LearnC++
//
//  Created by cy on 2021/4/20.
//

#ifndef _1_MergeTwoLists_h
#define _1_MergeTwoLists_h

#pragma once
#include "../Base.h"

class _21_MergeTwoLists_h : public BASE {
    
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}
        ListNode(int x, ListNode* next): val(x), next(next) {}
    };
        
public:
//21. 合并两个有序链表
//    将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
//    输入：l1 = [1,2,4], l2 = [1,3,4]
//    输出：[1,1,2,3,4,4]
    
    virtual void main()
    {
        vector<int> v1 = {1,2,4};
        vector<int> v2 = {1,3,4};
        ListNode* l1 = init(v1);
        ListNode* l2 = init(v2);
        
        ListNode* n = mergeTwoLists(l1, l2);
        outPut(n);
    }
    
//    这道题目用递归真的很好理解。
//    1. 终止条件：当两个链表都为空时，表示我们对链表已合并完成。
//    2. 如何递归：我们判断 l1 和 l2 头结点哪个更小，然后较小结点的 next 指针指向其余结点的合并结果。（调用递归）
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    
//    用数组初始化链表
    ListNode* init(vector<int> v) {
//        创建头指针
        ListNode* head = new ListNode();
        ListNode* a = new ListNode(v[0]);
        head->next = a;
        for(int i = 1 ; i < v.size() ; i++)
        {
            ListNode* b = new ListNode(v[i]);
            a->next = b;
            a = a->next;
        }
        return head;
    }
    
//  输出链表
    void outPut(ListNode* l) {
        cout << "output: ";
        while(l->next != nullptr) {
            l = l->next;
            cout << l->val << " ";
        }
        cout << endl;
    }
};

#endif /* _1_MergeTwoLists_h */
