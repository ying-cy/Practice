//
//  DeleteLinkListedElem.h
//  LearnC++
//
//  Created by cy on 2021/4/15.
//

#ifndef DeleteLinkListedElem_h
#define DeleteLinkListedElem_h

#pragma once
#include "../Base.h"

struct ListNodeD{
    int val;
    ListNodeD* next;
    ListNodeD() : val(0), next(nullptr) {}
    ListNodeD(int x) : val(x), next(nullptr) {}
    ListNodeD(int x, ListNodeD* next) : val(x), next(next) {}
};

class _DeleteLinkListedElem_h : public BASE {
public:
    virtual void main()
    {
        ListNodeD* node1 = new ListNodeD();
        ListNodeD* node2 = new ListNodeD();
        ListNodeD* node3 = new ListNodeD();
        ListNodeD* node4 = new ListNodeD();
        ListNodeD* node5 = new ListNodeD();

        node1->val = 1;
        node1->next = node2;

        node2->val = 2;
        node2->next = node3;

        node3->val = 2;
        node3->next = node4;

        node4->val = 3;
        node4->next = node5;
        
        node5->val = 2;
        node5->next = nullptr;
        
        int val = 2;
        removeElements(node1, val);
        Print(node1);
    }
    
    ListNodeD* removeElements(ListNodeD* head, int val) {
         ListNodeD* dummy = new ListNodeD(0, head);
         ListNodeD* first = dummy;
         while(first->next != nullptr)
         {
             if(first->next->val == val)
             {
                 first->next = first->next->next;
             }else{
                 first = first->next;
             }
         }
         return dummy->next;
    }
    
    //print
    void Print(ListNodeD* head)
    {
        while(head != nullptr)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }
};

#endif /* DeleteLinkListedElem_h */
