//
//  FastSlowPointer.h
//  LearnC++
//
//  Created by cy on 2021/4/15.
//

#ifndef FastSlowPointer_h
#define FastSlowPointer_h

#pragma once
#include "../Base.h"

struct ListNodeB {
    int val;
    ListNodeB* next;
    ListNodeB() : val(0), next(nullptr) {}
    ListNodeB(int x) : val(x), next(nullptr) {}
    ListNodeB(int x, ListNodeB* next) : val(x), next(next) {}
};

class _FastSlowPointer_h : public BASE {
public:
    virtual void main()
    {
        ListNodeB* node1 = new ListNodeB();
        ListNodeB* node2 = new ListNodeB();
        ListNodeB* node3 = new ListNodeB();
        ListNodeB* node4 = new ListNodeB();
        ListNodeB* node5 = new ListNodeB();
        ListNodeB* node6 = new ListNodeB();
        ListNodeB* node7 = new ListNodeB();
        ListNodeB* node8 = new ListNodeB();

        node1->val = 1;
        node1->next = node2;

        node2->val = 3;
        node2->next = node3;

        node3->val = 5;
        node3->next = node4;

        node4->val = 7;
        node4->next = node5;
        
        node5->val = 9;
        node5->next = node6;
        
        node6->val = 11;
        node6->next = nullptr;
        
        node7->val = 2;
        node7->next = node8;
        
        node8->val = 4;
        node8->next = node5;
        
//        bool result;
//        result = hasCycle(node1);
//
//        ListNodeB* resultNode = new ListNodeB();
//        resultNode = detectCycle(node1);
//        cout << "val: " << resultNode->val << endl;
        
        ListNodeB* r = new ListNodeB();
//        r = getIntersectionNode(node1, node7);
        
        int n = 6;
        cout << "链表：" << endl;
        Print(node1);
        r = removeNthFromEnd(node1, n);
        cout << "删除后：" << endl;
        Print(r);
        
        delete node1;
    }
    
    //1、只是判断有无环
    //思路：利用快慢指针，如果快指针可以追上慢指针，那么说明有环，否则无环。
    bool hasCycle(ListNodeB* head){
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNodeB* fastPointer = head->next;
        ListNodeB* slowPointer = head;

        while(fastPointer != slowPointer)
        {
            if(fastPointer == nullptr || fastPointer->next == nullptr)
            {
                return false;
            }
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
        }
        return true;
    }
    
    //2、返回相遇的链表结点
    //思路：快慢指针。首先两指针从头一起出发，第一次相遇的位置，可以通过计算得知，慢指针走的步数为nb，（n是常数，b为环中的节点数）；快指针走的步数为2nb。快指针重新指向头节点，慢指针再走一圈，就能发现距离环的初始位置。
    ListNodeB* detectCycle(ListNodeB* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        ListNodeB* fastPointer = head;
        ListNodeB* slowPointer = head;

        // 当快指针和慢指针相遇的时候，该结点并不一定是入环结点。需要构造第二次相遇。
        while(true)
        {
            if(fastPointer == nullptr || fastPointer->next == nullptr)
            {
                return nullptr;
            }
            fastPointer = fastPointer->next->next;
            slowPointer = slowPointer->next;
            if(fastPointer == slowPointer)
                break;
        }
        
        fastPointer = head;
        while (fastPointer != slowPointer) {
            fastPointer = fastPointer->next;
            slowPointer = slowPointer->next;
        }
        
        return fastPointer;
    }
        
    //3、判断链表是否相交
    //很浪漫的算法题：你走我来时的路，我走你来过的路，如果有缘，会在交汇点相遇。
    ListNodeB* getIntersectionNode(ListNodeB* headA, ListNodeB* headB){
        if(headA == nullptr || headB == nullptr)
            return nullptr;
        
        ListNodeB* nodeA = headA;
        ListNodeB* nodeB = headB;
        while(nodeA != nodeB)
        {
            nodeA = nodeA != nullptr ? nodeA->next : headB;
            nodeB = nodeB != nullptr ? nodeB->next : headA;
        }
        return nodeB;
    }

    //4、删除链表的倒数第N个节点
    ListNodeB* removeNthFromEnd(ListNodeB* head, int n) {
        ListNodeB* dummy = new ListNodeB(0, head);
        ListNodeB* slow = dummy;
        ListNodeB* fast = dummy;
        for(int i = 0 ; i <= n ; i++)
        {
            fast = fast->next;
        }
        
        while(fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
        slow->next = slow->next->next;
        ListNodeB* ans = dummy->next;
        
        delete dummy;
        return ans;
    }
    
    //print
    void Print(ListNodeB* head)
    {
        while(head != nullptr)
        {
            cout << head->val << endl;
            head = head->next;
        }
    }
};

#endif /* FastSlowPointer_h */
