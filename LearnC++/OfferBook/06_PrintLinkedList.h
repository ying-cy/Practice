//#include "../Base.h"
//
//#include<stack>
//
////问题6：从尾到头打印链表
////题目：输入一个链表的头结点，从尾到头反过来打印出每个节点的值。
////可以看看：https://www.cnblogs.com/kevinsharif/p/9216807.html
//
////思路：这个会联想到 栈，后进先出。从头到尾部遍历链表保存到栈中，再从栈顶开始输出值。
//
//struct ListNode
//{
//    int m_nKey;//存储一个值
//    ListNode* m_pNext;//存储一个指向下一个数据的指针
//};
//
//class _6_PrintLinkedList_h : public BASE {
//public:
//    virtual void main()
//    {
//        ListNode* node1 = new ListNode();
//        ListNode* node2 = new ListNode();
//        ListNode* node3 = new ListNode();
//
//        node1->m_nKey = 1;
//        node1->m_pNext = node2;
//
//
//        node2->m_nKey = 2;
//        node2->m_pNext = node3;
//
//
//        node3->m_nKey = 3;
//        node3->m_pNext = nullptr;
//
//        ListNode** headNode = &node1;
//
//        AddToTail(headNode, 4);
//    }
//
//    void PrintNode(ListNode* pHead)
//    {
//        stack<int> s;
//        ListNode* pNode = pHead;
//        //要注意一下这里！！！！如果你判断的是pNode->的指针是不是空的，那么到了最后一个循环就结束了,最后一个就没有执行while里面的语句，就没有被push进去
//        while (pNode != nullptr)
//        {
//            s.push(pNode->m_nKey);
//            pNode = pNode->m_pNext;
//        }
//        while (!s.empty())
//        {
//            cout << s.top();
//            s.pop();
//        }
//
//    }
//
//    //函数的第一个参数pHead是一个指向指针的指针。
//    //因为当我们往一个空链表中插入一个节点时，新插入的节点就是链表的头指针。由于此时会改动头指针，因此必须把pHead参数设为指向指针的指针。
//
//    //函数作用：在链表的末尾添加一个节点
//    //思路
//    //1、要添加节点，就要创建出这个节点的结构，然后让链表末尾的指针指向这个节点
//    //2、需要考虑：这个链表是不是空的，如果是空的，那么加入的指针是头指针。
//    void AddToTail(ListNode** pHead, int value)
//    {
//        ListNode* newNode = new ListNode();
//        newNode->m_nKey = value;
//        newNode->m_pNext = nullptr;
//
//        ListNode* headNode = *pHead;
//        if (*pHead == nullptr) {
//            *pHead = newNode;
//        }
//        else {
//
//            while (headNode->m_pNext != nullptr)
//            {
//                headNode = headNode->m_pNext;
//            }
//            headNode->m_pNext = newNode;
//        }
//
//        PrintNode(*pHead);
//    }
//
//};
