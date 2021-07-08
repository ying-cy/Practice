////
////  234_isPalindrome.h
////  LearnC++
////
////  Created by cy on 2021/7/5.
////
//
//#ifndef _34_isPalindrome_h
//#define _34_isPalindrome_h
//
//#pragma once
//#include "../Base.h"
//
//// Definition for singly-linked list.
//struct ListNode {
//    int val;
//    ListNode *next;
//    ListNode() : val(0), next(nullptr) {}
//    ListNode(int x) : val(x), next(nullptr) {}
//    ListNode(int x, ListNode *next) : val(x), next(next) {}
//};
//
//class _234_isPalindrome_h : public BASE {
//public:
//    virtual void main()
//    {
//        vector<int> v1 = {1,2,3,2,1};
//        ListNode* head = init(v1);
//        
//        bool result = isPalindrome(head);
//        cout << " ======== " << result;
//    }
//    
//    bool isPalindrome(ListNode* head) {
//// 有两个解题思路。
//// 思路1：将链表复制到数组中；然后用双指针，一个指向最前面，一个指向最后面，一起往中间走，开始比较。
//
//// 思路2：
////    1. 用快慢指针找到链表中间位置(快慢指针)，若链表有奇数个节点，则中间的节点应该看作是前半部分。
////    2. 反转链表
////    3. 比较前后链表的值
////    4. 反转回来
//        if (head == nullptr) {
//            return true;
//        }
//        
//        cout << "初始链表：" << endl;
//        Print(head);
//        cout << "==========" << endl;
//        
//        // 通过快慢指针找到前半部分链表的尾节点, 并反转后半部分链表
//        ListNode* firstHalfEnd = endOfFirstHalf(head);
//        cout << "中间值：" << firstHalfEnd->val << endl;
//        cout << "前半部分链表：" << endl;
//        Print(firstHalfEnd);
//        cout << "==========" << endl;
//        
//        ListNode* secondHalfStart = reverse(firstHalfEnd->next);
//        cout << "后半部分链表：" << endl;
//        Print(secondHalfStart);
//        cout << "==========" << endl;
//        
//        
//        cout << "反转完后的链表：" << endl;
//        Print(head);
//        
//        ListNode* first = head;
//        ListNode* second = secondHalfStart;
//        
//        bool result = true;
//        while(result && second != nullptr) {
//            if(first->val != second->val) {
//                result = false;
//            }else {
//                first = first->next;
//                second = second->next;
//            }
//            
//        }
//        firstHalfEnd->next = reverse(secondHalfStart);
//        cout << "结束链表：" << endl;
//        Print(head);
//        return result;
//        
//    }
//    
//    ListNode* endOfFirstHalf(ListNode* head) {
//        ListNode* fast = head;
//        ListNode* slow = head;
//        while (fast->next != nullptr && fast->next->next != nullptr) {
//            fast = fast->next->next;
//            slow = slow->next;
//        }
//        return slow;
//    }
//    
//    ListNode* reverse(ListNode* head) {
//        ListNode* pre = nullptr;
//        ListNode* curr = head;
//        ListNode* next = nullptr;
//        while(curr != nullptr) {
//            next = curr->next;
//            curr->next = pre;
//
//            pre = curr;
//            curr = next;
//        }
//        return pre;
//    }
//    
//    
//    
//    //    用数组初始化链表
//    ListNode* init(vector<int> v) {
////        创建头指针
//        ListNode* head = new ListNode();
//        ListNode* a = new ListNode(v[0]);
//        head->next = a;
//        for(int i = 1 ; i < v.size() ; i++)
//        {
//            ListNode* b = new ListNode(v[i]);
//            a->next = b;
//            a = a->next;
//        }
//        return head->next;
//    }
//    
//    //print
//    void Print(ListNode* head)
//    {
//        while(head != nullptr)
//        {
//            cout << head->val << endl;
//            head = head->next;
//        }
//    }
//};
//
//#endif /* _34_isPalindrome_h */
