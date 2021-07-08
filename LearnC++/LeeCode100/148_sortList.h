//
//  148_sortList.h
//  LearnC++
//
//  Created by cy on 2021/7/8.
//

#ifndef _48_sortList_h
#define _48_sortList_h

#pragma once
#include "../Base.h"


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class _148_sortList_h : public BASE {
public:
    virtual void main()
    {
        vector<int> v1 = {4, 2, 1, 3};
        ListNode* l1 = init(v1);
        
        ListNode* n = sortList(l1);
        outPut(n);
    }
    // 对链表自顶向下归并排序的过程如下。
    //     1. 找到链表的中点，以中点为分界，将链表拆分成两个子链表。寻找链表的中点可以使用快慢指针的做法，快指针每次移动 2 步，慢指针每次移动 1 步，当快指针到达链表末尾时，慢指针指向的链表节点即为链表的中点。
    //     2. 对两个子链表分别排序。
    //     3. 将两个排序后的子链表合并，得到完整的排序后的链表。可以使用「21. 合并两个有序链表」的做法，将两个有序的子链表进行合并。
    // 上述过程可以通过递归实现。递归的终止条件是链表的节点个数小于或等于 1，即当链表为空或者链表只包含 1 个节点时，不需要对链表进行拆分和排序。
    
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr);
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        // 递归的终止条件：当链表为空或者链表只包含 1 个节点时
        if (head == nullptr) {
            return head;
        }
        
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }

        // 用快慢指针找到链表的中点
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != tail) {
            slow = slow->next;
            fast = fast->next;
            // 防止循环条件出错，直接fast->next->next会有问题
            if(fast != tail)
                fast = fast->next;
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }
    
    // 合并两个有序链表
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        
        if (l1->val <= l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        }else{
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
    
    
    
    //    用数组初始化链表
    ListNode* init(vector<int> v) {
        //    创建头指针
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

#endif /* _48_sortList_h */
