#include "../Base.h"

//对树这个数据结构有四种遍历方式：前序遍历、中序遍历、后序遍历、层次遍历
//这几种遍历方式应该很熟悉


//题目7：重建二叉树
//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树，并输出其头结点。
//
//解题思路：
//前序遍历 --> 头  左  右
//中序遍历 --> 左  头  右

struct BinaryTreeNode
{
    int data;
    BinaryTreeNode* lchild, * rchild;
};

class _07_RebuildBinaryTree_h : public BASE {
public:
    virtual void main()
    {
        int preorder[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
        int inorder[] = { 4, 7, 2, 1, 5, 3, 8, 6 };
        BinaryTreeNode *result = Construct(preorder, inorder, 8);
        Print(result);
    }
    
    BinaryTreeNode* ConstructCore(int* preStartOrder, int* preEndOrder, int* inStartOrder, int* inEndOrder)
    {
        int root = preStartOrder[0];
        BinaryTreeNode* tree = new BinaryTreeNode();
        tree->data = root;
        tree->lchild = tree->rchild = nullptr;

        if (preStartOrder == preEndOrder)
        {
            if (inStartOrder == inEndOrder && *preStartOrder == *preEndOrder)
                return tree;
            cout << "Invalid input";
        }


        //需要在中序遍历里面找到root值
        int* rootIndex = inStartOrder;
        while (rootIndex <= inEndOrder && *rootIndex != root)
            rootIndex++;

        //if(rootIndex <= inStartOrder )

        //在中序中找到root值了以后，就可以知道中序左边的数量，从而确定先序遍历的指针末尾指向位置
        long length = rootIndex - inStartOrder;
        int* preLeftIndex = preStartOrder + length;

        if (length > 0)
        {
            tree->lchild = ConstructCore(preStartOrder + 1, preLeftIndex, inStartOrder, rootIndex - 1);
        }
        if (length < preEndOrder - preStartOrder)
        {
            tree->rchild = ConstructCore(preLeftIndex + 1, preEndOrder, rootIndex + 1, inEndOrder);
        }
        return tree;
    }

    BinaryTreeNode* Construct(int* preOrder, int* inOrder, int length)
    {
        if (preOrder == nullptr || inOrder == nullptr || length <= 0)
            return nullptr;

        return ConstructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
    }

    //用中序遍历打印二叉树
    void Print(BinaryTreeNode* tree)
    {
        BinaryTreeNode* root = tree;
        if (root != NULL)
        {
            Print(tree->lchild);
            cout << tree->data;
            Print(tree->rchild);
        }
    }
};
