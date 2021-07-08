//
//  19_DeleteLinkedNode.h
//  LearnC++
//
//  Created by cy on 2021/4/9.
//

#ifndef _9_DeleteLinkedNode_h
#define _9_DeleteLinkedNode_h

#pragma once
#include "../Base.h"

//19. 删除链表的倒数第 N 个结点
//
//给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
//
//进阶：你能尝试使用一趟扫描实现吗？

struct ListN{
    int val;
    ListN* next;
    ListN(): val(0), next(nullptr) {}
    ListN(int x): val(x), next(nullptr) {}
    ListN(int x,ListN* next) : val(x), next(next) {}
};

class _19_DeleteLinkedNode_h : public BASE {
public:
    virtual void main()
    {
        ListN* node1 = new ListN();
        ListN* node2 = new ListN();
        ListN* node3 = new ListN();

        node1->val = 1;
        node1->next = node2;

        node2->val = 2;
        node2->next = node3;

        node3->val = 3;
        node3->next = nullptr;
        
        int n = 2;
        ListN* r = nullptr;
        r = removeNthFromEnd(node1, n);
        Print(r);
    }
    
    ListN* removeNthFromEnd(ListN* head, int n)
    {
        ListN* dummy = new ListN(0, head);
        ListN* slow = dummy;
        ListN* fast= dummy;
        
        for(int i = 0 ; i <= n ; i++)
        {
            fast = fast->next;
        }
        
        while(fast)
        {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        
        ListN* re = dummy->next;
        delete dummy;
        return re;
    }
    
    
    //print
    void Print(ListN* head)
    {
        while(head != nullptr)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }

};

#endif / _9_DeleteLinkedNode_h /
