//
//  02_AddTwoNum.h
//  LearnC++
//
//  Created by cy on 2021/4/13.
//

#ifndef _2_AddTwoNum_h
#define _2_AddTwoNum_h

#pragma once
#include "../Base.h"

//2、两数相加
//给你两个非空的链表，表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，并且每个节点只能存储一位数字。
//
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

struct ListNode02 {
    int val;
    ListNode02 *next;
    ListNode02() : val(0), next(nullptr) {}
    ListNode02(int x) : val(x), next(nullptr) {}
    ListNode02(int x, ListNode02 *next) : val(x), next(next) {}
};

class _02_AddTwoNum_h : public BASE {
public:
    virtual void main()
    {
        ListNode02* node1 = new ListNode02(2);
        ListNode02* n1 = node1;
        
//        for(int i = 1 ; i < 7 ; i++)
//        {
//            n1->next = new ListNode02(9);
//            n1 = n1->next;
//        }

        ListNode02* node2 = new ListNode02(4);
        ListNode02* n2 = node2;
        
//        for(int i = 1 ; i < 4 ; i++)
//        {
//            n2->next = new ListNode02(9);
//            n2 = n2->next;
//        }
        
        ListNode02* node3 = new ListNode02();
        ListNode02* node4 = new ListNode02();
        ListNode02* node5 = new ListNode02();
        ListNode02* node6 = new ListNode02();
        ListNode02* node7 = new ListNode02();

        node1->val = 2;
        node1->next = node2;

        node2->val = 4;
        node2->next = node3;

        node3->val = 3;
        node3->next = nullptr;

        node4->val = 5;
        node4->next = node5;

        node5->val = 6;
        node5->next = node6;
        
        node6->val = 4;
        node6->next = nullptr;

        node7->val = 9;
        node7->next = nullptr;

        ListNode02* r = addTwoNumbers(node1, node4);
        
        cout << "result:" << endl;
        Print(r);
    }
    
//    思路：
//      1、首先对比一下两个链表的长度
//      2、哪个短，就往后面补0
//      3、开始相加
    ListNode02* addTwoNumbers(ListNode02* l1, ListNode02* l2)
    {
        int len1 = 1, len2 = 1;
        ListNode02* k1 = l1;
        ListNode02* k2 = l2;
        while (k1->next != nullptr) {
            len1++;
            k1 = k1->next;
        }
        while (k2->next != nullptr){
            len2++;
            k2 = k2->next;
        }
        cout << "len1: " << len1 << endl << "len2: " << len2 << endl;
        
        if(len1 > len2)
        {
            int w = len1 - len2;
            for(int k = 0 ; k < w ; k++)
            {
                k2->next = new ListNode02(0);
                k2 = k2->next;
            }
        }else{
            int w = len2 - len1;
            for(int k = 0 ; k < w ; k++)
            {
                k1->next = new ListNode02(0);
                k1 = k1->next;
            }
        }
        cout << "l1:" << endl;
        Print(l1);
        cout << "l2:" << endl;
        Print(l2);
        
        
        bool carry = false;
        ListNode02* l3 = new ListNode02();
        ListNode02* cur = l3;

        while(l1 != nullptr)
        {
            int r = l1->val + l2->val + carry;
            cur->next = new ListNode02(r % 10);
            carry = r > 9 ? true : false;
            
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }
        
        if(carry)
        {
            cur->next = new ListNode02(1);
            cur = cur->next;
        }
        
        return l3->next;
    }
    
    //print
    void Print(ListNode02* head)
    {
        while(head != nullptr)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }
};



#endif / _2_AddTwoNum_h /
