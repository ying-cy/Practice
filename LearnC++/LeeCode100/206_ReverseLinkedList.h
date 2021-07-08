//
//  206_ReverseLinkedList.h
//  LearnC++
//
//  Created by cy on 2021/4/15.
//

#ifndef _06_ReverseLinkedList_h
#define _06_ReverseLinkedList_h

#pragma once
#include "../Base.h"

struct LinkListR{
    int val;
    LinkListR* next;
    LinkListR() : val(0), next(nullptr) {}
    LinkListR(int x) : val(x), next(nullptr) {}
    LinkListR(int x, LinkListR* next) : val(x), next(next) {}
};

class _206_ReverseLinkedList_h : public BASE {
public:
    virtual void main()
    {
        LinkListR* node1 = new LinkListR();
        LinkListR* node2 = new LinkListR();
        LinkListR* node3 = new LinkListR();
        LinkListR* node4 = new LinkListR();
        LinkListR* node5 = new LinkListR();

        node1->val = 1;
        node1->next = node2;

        node2->val = 2;
        node2->next = node3;

        node3->val = 3;
        node3->next = node4;

        node4->val = 4;
        node4->next = node5;
        
        node5->val = 5;
        node5->next = nullptr;
        
        cout << "output:" << endl;
        Print(node1);
        LinkListR* r;
        r = reverseList(node1);
        Print(r);
    }
    
    // 方法一：局部反转
    LinkListR* reverseList(LinkListR* head)
    {
        LinkListR* prev = nullptr;
        LinkListR* ptr = head;
        LinkListR* next = nullptr;
        
        while(ptr){
            next = ptr->next;
            ptr->next = prev;
            
            prev = ptr;
            ptr = next;
        }
        
        return prev;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//        LinkListR* first = nullptr;
//        LinkListR* second = head;
//        LinkListR* tmp = second->next;
//
//        while(second){
//            tmp = second->next;
//
//            second->next = first;
//            first = second;
//            second = tmp;
//        }
//        return first;
    }
    
    //方法二：递归实现
    LinkListR* reverseList02(LinkListR* head)
    {
        //递归终止条件是当前为空，或者下一个节点为空
        if(head == nullptr || head->next == nullptr) {
            return head;
        }
        //这里的cur就是最后一个节点
        LinkListR* cur = reverseList02(head->next);

        head->next->next = head;
        
        //防止链表循环，需要将head.next设置为空
        head->next = nullptr;
        
        //每层递归函数都返回cur，也就是最后一个节点
        return cur;
    }
    
    
    //print
    void Print(LinkListR* head)
    {
        while(head != nullptr)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }

};
#endif /* _06_ReverseLinkedList_h */
