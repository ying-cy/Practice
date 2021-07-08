//
//  104_MaxDepth.h
//  LearnC++
//
//  Created by cy on 2021/5/20.
//

#ifndef _04_MaxDepth_h
#define _04_MaxDepth_h

#pragma once
#include "../Base.h"

class _104_MaxDepth_h : public BASE {
//    定义树
     struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
     };
    
public:
//    104. 二叉树的最大深度
//    给定一个二叉树，找出其最大深度
    virtual void main()
    {
        vector<int> t = {3, 9, 20, NULL, NULL, 15, 7};
        TreeNode* head = initBTree(t);
        Print(head);
        
        int d = maxDepth(head);
        cout << endl << "depth: " << d;
    }
    
    // 用数组初始化一颗二叉树
    TreeNode* initBTree(vector<int> elements) {
        int size = (int)elements.size();
        if (size < 1)
        {
            return NULL;
        }
        
        //动态申请size大小的指针数组
        TreeNode **nodes = new TreeNode*[size];
        //将int数据转换为TreeNode节点
        for (int i = 0; i < size; i++) {
            if (elements[i] == 0) {
                nodes[i] = NULL;
            } else {
                nodes[i] = new TreeNode(elements[i]);
            }
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(nodes[0]);
     
        TreeNode *node;
        int index = 1;
        while (index < size) {
            node = nodeQueue.front();
            nodeQueue.pop();
            nodeQueue.push(nodes[index++]);
            node->left = nodeQueue.back();
            nodeQueue.push(nodes[index++]);
            node->right = nodeQueue.back();
        }
        return nodes[0];
    }
    
//    输出二叉树的最大深度值
//    思想：递归
    int maxDepth(TreeNode* root) {
        // 递归终止条件
        if(root == nullptr){
            return 0;
        }else{
            // 本层应该做的事情
            int leftN = maxDepth(root->left);
            int rightN = maxDepth(root->right);
            // 返回值
            return max(leftN, rightN) + 1;
        }
    }
    
    // 前序遍历输出二叉树的值
    void Print(TreeNode* tree)
    {
        TreeNode* root = tree;
        if (root != NULL)
        {
            cout << tree->val << " ";
            Print(tree->left);
            Print(tree->right);
        }
    }
    
};

#endif /* _04_MaxDepth_h */
